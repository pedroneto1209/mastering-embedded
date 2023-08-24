### Compiler
`#` means its a preprocessor statement, the include just copies everything from the library to our main file

Operators are in fact, functions: 
```cpp 
std::cout << "Hello World!" << std::endl;
```
The `<<` operator makes cout receive the string "Hello World!" and the endline parameter

```#pragma once``` means the header will only be exported once in the binary, it was usually used as:
```cpp
#ifndef _HEADER_H 
#define _HEADER_H 
#endif
```

The ```cin.get()``` just waits for Enter to end the code

A bool is actually 1 byte instead of 1 bit, because we can't access 1 bit in the memory
 
### Flow control
 The if statement checks if its zero, so whenever you are trying to check if a function ran correctly just ```if (!function())```, this is usefull because you deal with return pointers and they can be `NULL`, which means 0
 you can format like this `if(variable) Function();` without brackets if its only one command

 for loop stands like `for(declaration; condition; iteration)`, thats why `for(;;)` is an infinite loop

 flow control:
 - continue: goes to next iteration
 - break: gets out of the loop
 - return: gets out of the whole function

### Pointers
a void pointer is a typeless pointer, it doesn't need to have a type, types do not matter ever

a pointer to an array points to the first item in the array

### References
```int& ref = a;``` `ref` is going to be exactly like `a`, not equal, it's an alias, it even do not exist in the memory

you can use it in a function parameter, so when you pass it will act in the actual variable:
```cpp
void Function(int value) {
    value++;
}

void Function2(int& value) {
    value++;
}

int a = 5;
Function(a); // this will not change a to 6
Function2(a); // this WILL change a to 6
```

the variable passed to a reference can't change and it has to be referenced in the reference creation

### Classes

by default the variables inside a class are private, if you want to use them outside you declare inside the `public:` area, this is actually the only difference between a `class` and a `struct`, where you can actually write `private` inside, this even means if you want to convert `C` into `C++` you could just do ```#define struct class```

One convention possible is to use structs to something simple, like the representation of a vector, with module methods, etc. And a class to something more meaningful, like a player with vector positions and so on.

You can instantiate a class by using list-initialization like this:
```cpp
class Entity {
    int x, y;
}

Entity entity = {1, 2};
```
 NOTE: creating classes with `new` uses `malloc()`, it is created in heap

### Static

- Outside of a class, `static` will only be used in the scope it is declared
  - the `extern` it's like the opposite, it will reference the defined variable/function to the same variable defined in another global scope
  - it's a good practice to use static every time if you don't need the variable/function in another scopes
- Inside a class, `static` will be instantiated once for every instance of the class
  - when using static the variables are no longer class members, so the list initializer will not work
  - it needs to be instantiated because just the static define will not alloc memory for those variables
  - after instantiated like `int Entity::x;`, it makes no sense to assign values like `entity.x = 10`, the correct way would be `Entity::x = 10;`
  - In resume, they dont belong to the class, but actually they do as they are sensitive to public and private defines for example, this means they work like global variables but they are more organized as they belong to the class because they may have something to do with it
  - for static methods, they don't have an instance, so you can't access normal variables inside a class with them, they work just like global static functions

### Enums
 Enum is like a dict in python: 
 ```cpp
 enum Example : unsigned char { // the int type can be specified
    A = 0, B, C; // the values can be set, starts at 0 by default
 }

 Example selected = C; // this has to be one of the defined
 ```

 ### Constructors
 When you have a class such as Entity defined before, x and y are not initialized, the constructor `Entity()` is a function inside the class to initialize these parameters: 
 ```cpp
class Entity {
public:
    int X, Y;
    Entity(int x, int y) {
        X = x;
        Y = y;
    }
} 
 ```
 What may be helpful is to make the constructor private so you can't instantiate the class `Log log; log.Write();`, it will only be used with static methods for example `Log::Write();`, if you don't want to specify the constructor to be private but also don't want the default constructor you can make `Log() = delete;

 
 ### Destructors
 `~Entity(){}` runs when `entity.~Entity()` is called, but this usually happen when the instance is created inside a function, so when the function finish running the instance is destroyed

 ### Inheritance
 - The class created by inheritance is actually both types, this means you could pass Player for a function that requires Entity for example
 - `class Player : public Entity`

### Virtual Functions
They overwrite the methods of the class we are inheriting, if you were to just write a normal method with the same name it would not work, because even though calling Player would work, calling Player as type Entity for example would just use the method from Entity instead of Player, to fix this, you should change the base function of the base class to be overwritable, which means calling it virtual:
```cpp
// inside Entity
virtual std::string getName() {

}
```
Also, it is not mandatory but it is the best practice to make clear Player's getName is an override:
```cpp
// inside Player
std::string getName() override {

}
```

NOTE FOR EMBEDDED: Virtual functions have a cost, the V-Table has to contain the function pair so it takes more memory and when the virtual function runs it has to check this V-Table for the override function so this means more clock cycles.

### Interfaces - Pure Virtual Functions
Its a virtual function that doesnt have a default implementation, its declared but its only implemented in the subclassess
```cpp
// inside Entity
virtual std::string getName() = 0;
```
You can only `instantiate` a class that have all methods implemented, so in this case you couldnt instantiate Entity nor Player if it didn't had the function

### Visibility
Its not something the CPU understand, its only good practice

In terms of variable and methods access
- private: only class "friends" and internally can be accessed.
- protected: can be accessed by subclasses but cant be accessed outside.
- public: can be accessed outside by everyone.

### Arrays
An array is actually a pointer to the first item, this means you could assign values as a pointer by dereferencing it:
`example[2] = 5` = `*(ptr + 2) = 5` = `*(int)((char*)ptr + 8) = 5 //you use char because it is 1 byte long, instead of ints 4 bytes`

When you reach array out of bounds you are accessing memory that isnt yours so this could go wrong

you could create an array in the stack `int example[5];` or in the heap `int* example = new int[5];`.
- in the stack, the memory will be destroyed when we reach the end bracket
- in the heap, we need to delete using `delete[] example`
this is useful to deal with lifetimes, if you have a function returning the array created inside, you would have to use in the heap to delete later, otherwise it would be deleted

For raw arrays you would have to keep track of their size, it is not recommended to try to calculate their size. But in C++11, it has one class for arrays that keeps track of the size, but is also more memory costly

To keep track, creating `example[size]`, size must be a compiler time known constant, so it would have to be `static const int size;`

NOTE FOR EMBEDDED: `<= 4` is more costly than `< 5` because it'll always check both operands
ALSO: if you create an array in the heap inside a class, the array would not be in the class memory exactly. In fact, the class memory would contain the array address, and in the address the array would be stored (also because the class would be in the stack and the array would be in heap), as the CPU would have to fetch this array in heap, it would be more costly in the performance

### Strings
char = 1B, its good to use it to access memory 

strings are immutable in size, because they are arrays, thats why you usualy use const = `const char* texto = "text";`

Every string has a null termination byte, it means that it has every ascii in memory from the address is starts and it finishes when it reachs the byte 00, this means that if you try to write a string by hand, if you don't end it with a 0 or '\0', the CPU will think the string is not over, if you print it, other than the name you want, it will print a lot of crap

You should use {<}string{>} in cpp, to do things like: 
```cpp
#include <string>

std::string name = std::string("Pedro") + " Neto"; // you need to convert to string class, if not, it would be like adding two char pointers
name.size();
bool contains = name.find("ro") != std::string::npos; // basically checking if the position of "no" is valid
```

NOTE FOR CLASSES TOO: You can't pass a class (or std::string) as parameter to a function and expect it to change the original string, because when passing, the function is actually instantiating a new class (or std::string) copying the passed class in `void Function(std::string string)`, this means any changes won't affect the original string and also means that even if you are reading only, it would not be memory effective. The way to do this properly is by passing a const (not changable) reference (not copying) to the function `void Function(const std::string& string)`, you still can't modify, but you can read without performance issues
Double "quotes" are char pointers, singles 'quotes' are single chars

### String literals
you can't modify a char pointer by assigning like this `char* string[3] = "the";  string[2] = 'o';` because this is an undefined behaviour (some compilers it might work but not in every, because string literal are usually saved in a read-only memory), you should declare it `const`. The only way to make this work is by using it as an char array, not an pointer `char string[] = "the";`

In fact, string literals are ALWAYS stored in read-only memory, even when we do `char string[] = "the";`, the assembly is copying the read-only string to an actual variable, and it is changing as a variable, and not the memory itself

Notice that is a helper in cpp called std::string_literals that has features to deal with these string defines and char types

Types:
```cpp

const char* name1 = u8"Pedro"; // 1B UTF8 char
const wchar_t* name2 = L"Pedro"; // 2B
const char16_t* name3 = u"Pedro"; // 2B UTF16 char
const char32_t* name4 = U"Pedro"; // 4B UTF32 char

const char* paragraph = R"Line1
Line2
Line3
Line4"; // R stands for row

// the following uses string_literals
using namespace std::string_literals;

std::string utf8String = u8"Hello, world!";
std::wstring wideString = L"Wide string"; 
std::u16string utf16String = u"UTF-16 string";
std::u32string utf32String = U"UTF-32 string";
std::u32string concatenated = U"Pedro"s + U" Neto";  // s suffix creates a std::string, instead of using std::string("Pedro") + " Neto"
```


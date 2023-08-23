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
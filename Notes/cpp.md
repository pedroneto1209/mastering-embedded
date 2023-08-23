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
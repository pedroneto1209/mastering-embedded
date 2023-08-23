# libraries
STATIC = Code is compiled into the executable, resulting in faster execution but larger file size. Recompilation needed for updates.

SHARED = Code is stored in separate files loaded at runtime. Smaller executables, but slight startup overhead. Easier updates.

MODULE = Supports dynamic loading of code modules. Enhanced modularity, reduced compilation time. Requires C++20 or later, slight runtime overhead.

# Commands
> cmake -S . -B build -G "MinGW Makefiles"
> 
> -S = main directory
> 
> -B = build directory
> 
> -G = compiler

> cmake --build .\build\

# Subdirectories

IMPORTANT = When dealing with subdirectories, the target_link_libraries(main PRIVATE log) in the main has to run after "log" is defined, so add_subdirectory(components) has to run BEFORE add_subdirectory(src)

target_include_directories(log PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src") specifies the directory that contains all libraries, anyone consuming this should use the same /src path

target_link_libraries(main PRIVATE log) sees that I'm linking the target "log" library to "main"

this means inside main.cpp the include would be relative to /src as the PUBLIC exposes the entire src folder

target_compile_definitions(log PUBLIC SAY_HELLO_VERSION=5) this PUBLIC will propagate to consumers, if PRIVATE will only be used by log, if INTERFACE will only be used by main
You use this command to define macros that affect the compilation process of the target.


> PUBLIC = Symbols are part of the library's API and are exposed to consumers. They will be linked when the library is used and its headers are included.
> 
> PRIVATE = Symbols are for internal use within the library. They are not exposed to consumers and are not linked when the library is used.
> 
> INTERFACE = Symbols that are part of the library's API, but are not linked into the library itself. They are used to specify the interface for consumers but do not affect the library's own build.


# Configuration Script
cmake_minimum_required(VERSION 3.27)
project(testProject VERSION 1.0.0) - testProject, VERSION and 1.0.0 are strings, every variable in CMake is a string
set(MYVARIABLE "Hello") - assign a variable, project command is basically a set(), it assigns PROJECT_VERSION and PROJECT_NAME
message(STATUS "${MYVARIABLE} World") - Print function

# Control Flow
> if("TRUE")
> 
> elseif()
> 
> else()
> 
> endif()

> while(my_value LESS "50")
> 
>     math(EXPR my_value "${my_value} + 1")
> 
> endwhile()

> foreach(idx RANGE 1 100 3)
> 
>     message(STATUS "Index is ${idx})
> 
> endforeach()

> if(NOT my_bool)
> 
> STREQUAL = compares two strings
> 
> EQUAL = compares arithmetically
> 
> MATCHES = checks substrings
> 
> LESS

# Functions

> set_property(GLOBAL PROPERTY FOO 1 2 3) = this sets FOO property (which is not a variable) to the list 1; 2; 3
>
> GLOBAL acts like the Mode of the function set_property, depending on the Mode the function will not always have the same parameter inputs, this means that set_property(DIRECTORY PROPERTY FOO 1 2 3) will do something completely different
>
> get_cmake_property(foo_value FOO)

> function(my_function first_arg)
>
> endfunction()
libraries
STATIC = Code is compiled into the executable, resulting in faster execution but larger file size. Recompilation needed for updates.
SHARED = Code is stored in separate files loaded at runtime. Smaller executables, but slight startup overhead. Easier updates.
MODULE = Supports dynamic loading of code modules. Enhanced modularity, reduced compilation time. Requires C++20 or later, slight runtime overhead.

PRIVATE = 


cmake -S . -B build -G "MinGW Makefiles"
-S = main directory
-B = build directory
-G = compiler

cmake --build .\build\
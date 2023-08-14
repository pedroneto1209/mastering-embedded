libraries
STATIC = 
SHARED = 
MODULE = 

PRIVATE = 


cmake -S . -B build -G "MinGW Makefiles"
-S = main directory
-B = build directory
-G = compiler

cmake --build .\build\
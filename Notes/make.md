libraries
STATIC = Code is compiled into the executable, resulting in faster execution but larger file size. Recompilation needed for updates.
SHARED = Code is stored in separate files loaded at runtime. Smaller executables, but slight startup overhead. Easier updates.
MODULE = Supports dynamic loading of code modules. Enhanced modularity, reduced compilation time. Requires C++20 or later, slight runtime overhead.

cmake -S . -B build -G "MinGW Makefiles"
-S = main directory
-B = build directory
-G = compiler

cmake --build .\build\


IMPORTANT = When dealing with subdirectories, the target_link_libraries(main PRIVATE log) in the main has to run after "log" is defined, so add_subdirectory(components) has to run BEFORE add_subdirectory(src)


target_include_directories(log PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src") specifies the directory that contains all libraries, anyone consuming this should use the same /src path

target_link_libraries(main PRIVATE log) sees that I'm linking the target "log" library to "main"

this means inside main.cpp the include would be relative to /src as the PUBLIC exposes the entire src folder

target_compile_definitions(log PUBLIC SAY_HELLO_VERSION=5) this PUBLIC will propagate to consumers, if PRIVATE will only be used by log, if INTERFACE will only be used by main
You use this command to define macros that affect the compilation process of the target.


PUBLIC = Symbols are part of the library's API and are exposed to consumers. They will be linked when the library is used and its headers are included.
PRIVATE = Symbols are for internal use within the library. They are not exposed to consumers and are not linked when the library is used.
INTERFACE = Symbols that are part of the library's API, but are not linked into the library itself. They are used to specify the interface for consumers but do not affect the library's own build.
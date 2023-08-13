#include <iostream>

int add(int a, int b) { return a + b; }

void add_log(int a, int b) { std::cout << add(a, b) << std::endl; }

int main() {

    // static

    add_log(4, 5);
    add_log(4, 6);
    add_log(7, 6);
}
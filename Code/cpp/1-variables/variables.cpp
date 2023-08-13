#include <iostream>

int main() {

    // bytes
    // 1 = char; 2 = short; 4 = int, long; 8 = long long

    unsigned int variable = 8;

    std::cout << variable << std::endl;

    char word = 'A';

    std::cout << word << std::endl;

    word = 65;

    std::cout << word << std::endl;

    short not_word = 65;

    std::cout << not_word << std::endl;

    float number_float = 5.5f;  // 4 bytes
    double number_double = 5.5; // 8 bytes

    std::cout << sizeof(float) << std::endl;
    std::cout << sizeof(double) << std::endl;
}
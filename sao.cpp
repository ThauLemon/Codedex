#include <iostream>

int main() {
    #if __cplusplus == 201703L
    std::cout << "C++17 is being used.\n";
    #else
    std::cout << "A different C++ standard is being used.\n";
    #endif
    return 0;
}


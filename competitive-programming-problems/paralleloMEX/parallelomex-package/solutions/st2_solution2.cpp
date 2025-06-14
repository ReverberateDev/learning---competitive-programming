// sol_n1.cpp
#include <iostream>

int main() {
    long long n, k, v;
    std::cin >> n >> k >> v;
    if (v > 1) {
        std::cout << 1 << std::endl;
    } else { // v == 1
        std::cout << 2 << std::endl;
    }
    return 0;
}
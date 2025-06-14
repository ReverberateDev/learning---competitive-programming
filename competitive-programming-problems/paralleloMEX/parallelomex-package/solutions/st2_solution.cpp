#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    long long k, v;
    std::cin >> n >> k >> v;
    if (v == 1) {
        std::cout << 2 << std::endl;
    } else {
        std::cout << 1 << std::endl;
    }
    return 0;
}
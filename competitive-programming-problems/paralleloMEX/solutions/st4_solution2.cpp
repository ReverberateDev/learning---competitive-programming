// sol_k1.cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    long long k;
    std::cin >> n >> k;
    std::vector<long long> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    std::sort(v.begin(), v.end());
    
    int available_count = 0;
    int v_ptr = 0;
    for (int i = 1; i <= n; ++i) {
        while (v_ptr < n && v[v_ptr] <= i) {
            available_count++;
            v_ptr++;
        }
        if (available_count > 0) {
            available_count--; // Use one available parallelogram
        } else {
            std::cout << i << std::endl;
            return 0;
        }
    }
    std::cout << n + 1 << std::endl;
    return 0;
}
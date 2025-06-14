// sol_k0.cpp
#include <iostream>
#include <vector>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    long long k;
    std::cin >> n >> k;
    std::set<long long> s;
    for (int i = 0; i < n; ++i) {
        long long v;
        std::cin >> v;
        s.insert(v);
    }
    long long mex = 1;
    while (s.count(mex)) {
        mex++;
    }
    std::cout << mex << std::endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

struct Seller {
    long long stock;
    int price;
    int id;
};

bool compareSellers(const Seller& a, const Seller& b) {
    return a.price < b.price;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    long long k;
    std::cin >> n >> k;

    std::vector<Seller> sellers(n);
    std::vector<long long> s_in(n);
    std::vector<int> p_in(n);

    for (int i = 0; i < n; ++i) std::cin >> s_in[i];
    for (int i = 0; i < n; ++i) std::cin >> p_in[i];

    for (int i = 0; i < n; ++i) {
        sellers[i] = {s_in[i], p_in[i], i};
    }

    std::cout << k * sellers[0].price << '\n';
}

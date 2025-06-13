#include <iostream>
#include <vector>
#include <algorithm>

struct Seller {
    long long stock;
    int price;
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
        sellers[i] = {s_in[i], p_in[i]};
    }

    std::sort(sellers.begin(), sellers.end(), compareSellers);

    long long total_cost = 0;

    for (const auto& seller : sellers) {
        if (k == 0) {
            break;
        }
        if (seller.stock == -1) {
            total_cost += k * seller.price;
            k = 0;
        } else {
            long long buy_amount = std::min(k, seller.stock);
            total_cost += buy_amount * seller.price;
            k -= buy_amount;
        }
    }

    std::cout << total_cost << std::endl;

    return 0;
}

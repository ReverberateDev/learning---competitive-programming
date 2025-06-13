#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

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

    // Sort sellers to process the cheapest ones first
    std::sort(sellers.begin(), sellers.end(), compareSellers);

    std::vector<long long> prices;
    for (const auto& seller : sellers) {
        // *** THE FIX IS HERE ***
        if (seller.stock == -1) {
            // This is the cheapest infinite source. We can fill the rest of our needs.
            // Add its price 'k' times to the list. This is a "safe" upper bound
            // on how many we might need from this source.
            for (long long i = 0; i < k; ++i) {
                prices.push_back(seller.price);
            }
            // Since we can get anything we need from here, we never need to check
            // more expensive sellers.
            break; 
        } else {
            // This is the original logic for finite stock, which is fine.
            for (int i = 0; i < seller.stock; ++i) {
                prices.push_back(seller.price);
            }
        }
    }

    long long total_cost = 0;
    // The 'prices' vector is already sorted by price due to the way it was built.
    // Sum the costs of the K cheapest items.
    for(long long i = 0; i < k; i++){
        total_cost += prices[i];
    }
    
    std::cout << total_cost << std::endl;
    return 0;
}
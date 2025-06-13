#include <iostream>
#include <vector>
#include <map>
#define int long long

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, q;
    std::cin >> n >> q;

    std::vector<int> cart;
    for (int i = 0; i < n; ++i) {
        int t;
        std::cin >> t;
        cart.push_back(t);
    }

    for (int i = 0; i < q; ++i) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int a;
            std::cin >> a;
            cart.push_back(a);
        } else {
            // On every query, build a frequency map from the entire cart
            std::map<int, int> temp_counts;
            for (int item : cart) {
                temp_counts[item]++;
            }

            int current_answer = 0;
            for (auto const& [key, val] : temp_counts) {
                if (val == 2) {
                    current_answer++;
                }
            }
            std::cout << current_answer << "\n";
        }
    }
    return 0;
}
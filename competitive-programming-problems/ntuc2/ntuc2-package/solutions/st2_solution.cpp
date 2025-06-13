#include <iostream>
#include <vector>
#include <map> // Using map, but unordered_map would work too
#define int long long

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, q;
    std::cin >> n >> q;

    std::map<int, int> counts;

    // Process initial N items
    for (int i = 0; i < n; ++i) {
        int t;
        std::cin >> t;
        counts[t]++;
    }

    // Process Q queries
    for (int i = 0; i < q; ++i) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int a;
            std::cin >> a;
            counts[a]++;
        } else {
            // Recalculate the answer from scratch for every query
            int current_answer = 0;
            for (auto const& [key, val] : counts) {
                if (val == 2) {
                    current_answer++;
                }
            }
            std::cout << current_answer << "\n";
        }
    }

    return 0;
}
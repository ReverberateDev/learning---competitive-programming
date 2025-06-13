#include <iostream>
#include <vector>
#include <unordered_map>
#define int long long
// Data structure to hold counts and the current answer
std::unordered_map<int, int> counts;
int perfect_pair_count = 0;

// Helper function to process adding a new item
void addItem(int type) {
    // Check the count BEFORE changing it
    if (counts.count(type) && counts[type] == 2) {
        // This type was a perfect pair, but now it won't be.
        perfect_pair_count--;
    }

    // Increment the count
    counts[type]++;

    // Check the count AFTER changing it
    if (counts[type] == 2) {
        // This type just became a perfect pair.
        perfect_pair_count++;
    }
}

signed main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, q;
    std::cin >> n >> q;

    // Process initial N items
    for (int i = 0; i < n; ++i) {
        int t;
        std::cin >> t;
        addItem(t);
    }

    // Process Q queries
    for (int i = 0; i < q; ++i) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int a;
            std::cin >> a;
            addItem(a);
        } else {
            std::cout << perfect_pair_count << "\n";
        }
    }

    return 0;
}
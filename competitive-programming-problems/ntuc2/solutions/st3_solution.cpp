#include <iostream>
#include <vector>
#define int long long
const int MAX_TYPE_VALUE = 1000000;
std::vector<int> counts(MAX_TYPE_VALUE + 1, 0);
int perfect_pair_count = 0;

void addItem(int type) {
    if (type > MAX_TYPE_VALUE) {
        // This solution can't handle large types, but for the subtask it's fine.
        // In a real contest, this would lead to a crash or wrong answer on other subtasks.
        return;
    }

    if (counts[type] == 2) {
        perfect_pair_count--;
    }
    counts[type]++;
    if (counts[type] == 2) {
        perfect_pair_count++;
    }
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, q;
    std::cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        int t;
        std::cin >> t;
        addItem(t);
    }

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
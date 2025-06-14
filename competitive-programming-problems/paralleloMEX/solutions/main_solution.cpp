// Full Solution (Corrected for K=0 bug)
#include <iostream>
#include <vector>
#include <map>
#include <set>

// Using long long for safety, though not all variables need it.
#define int long long

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    long long k;
    std::cin >> n >> k;

    std::map<long long, int> initial_counts;
    for (int i = 0; i < n; i++) {
        long long v;
        std::cin >> v;
        initial_counts[v]++;
    }

    // *** FIX: Handle K=0 as a special case ***
    if (k == 0) {
        std::set<long long> s;
        for(auto const& [val, count] : initial_counts) {
            s.insert(val);
        }
        long long mex = 1;
        while(s.count(mex)) {
            mex++;
        }
        std::cout << mex << '\n';
        return 0;
    }

    // The rest of the logic is for K > 0 and is correct.
    std::map<long long, int> bank;

    for (int i = 1; i <= n + 1; ++i) {
        if (initial_counts.count(i)) {
            bank[i % k] += initial_counts[i];
        }

        long long required_rem = i % k;
        
        if (bank[required_rem] > 0) {
            bank[required_rem]--;
        } else {
            std::cout << i << '\n';
            return 0;
        }
    }

    // This case is rare but possible if N+1 is constructible
    std::cout << n + 2 << '\n';

    return 0;
}
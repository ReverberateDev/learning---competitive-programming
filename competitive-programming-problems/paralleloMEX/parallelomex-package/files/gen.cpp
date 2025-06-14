#include "testlib.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    string type = argv[1];
    int n = atoi(argv[2]);
    long long k = atoll(argv[3]);
    long long max_v = atoll(argv[4]);

    cout << n << " " << k << endl;

    vector<long long> v(n);

    if (type == "random") {
        for (int i = 0; i < n; ++i) {
            v[i] = rnd.next(1LL, max_v);
        }
    } else if (type == "max_mex") {
        iota(v.begin(), v.end(), 1);
    } else if (type == "small_mex") {
        for (int i = 0; i < n; ++i) {
            v[i] = rnd.next(2LL, max_v);
        }
    } else if (type == "k0_evens") {
        for (int i = 0; i < n; ++i) {
            v[i] = 2LL * (i + 1);
        }
    } else if (type == "rem_heavy") {
        long long base_rem = (k > 0) ? rnd.next(0LL, k - 1) : 0;
        for (int i = 0; i < n; ++i) {
            long long val;
            if (k > 0) {
                 long long multiplier = rnd.next(0LL, (max_v - 1) / k);
                 val = multiplier * k + base_rem;
            } else {
                 val = rnd.next(1LL, max_v);
            }
            if (val == 0) val = (k > 0) ? k + base_rem : 1;
            v[i] = val;
        }
    } else if (type == "constructible") {
        int target_mex_approx = atoi(argv[5]);
        int seed_count = min(n, target_mex_approx - 1);
        for (int i = 0; i < seed_count; ++i) {
            v[i] = i + 1;
        }
        for (int i = seed_count; i < n; ++i) {
            v[i] = rnd.next(1LL, max_v);
        }
    } else if (type == "k1_killer") {
        // Creates a test to fail simple K=0 solutions on K=1 subtasks.
        // Usage: gen k1_killer N K max_v surplus_val surplus_count
        long long surplus_val = atoll(argv[5]);
        int surplus_count = atoi(argv[6]);
        ensure(surplus_count < n);

        // Fill with the surplus value
        for (int i = 0; i < surplus_count; ++i) {
            v[i] = surplus_val;
        }

        // Fill the rest with numbers that create a gap right after what's
        // constructible from the surplus values.
        long long gap_start = surplus_val + surplus_count;
        if (surplus_val != 1) {
            // A more general (but not needed for this problem) approach would be more complex.
            // For this problem, we only need to kill with surplus_val = 1.
            gap_start = surplus_count + 1; 
        }

        for (int i = surplus_count; i < n; ++i) {
            v[i] = rnd.next(gap_start, max_v);
        }
    }
    
    shuffle(v.begin(), v.end());

    for (int i = 0; i < n; ++i) {
        cout << v[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
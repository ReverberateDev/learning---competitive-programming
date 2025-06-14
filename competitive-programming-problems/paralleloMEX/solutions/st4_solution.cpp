// solution_k1.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long k; // k is always 1 here
    cin >> n >> k;
    vector<long long> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for (int i = 1; i <= n; ++i) {
        // To form the value 'i', we need to use a parallelogram with V[j] <= i.
        // We greedily use the i-th smallest parallelogram.
        if (v[i - 1] > i) {
            cout << i << endl;
            return 0;
        }
    }
    cout << n + 1 << endl;
    return 0;
}
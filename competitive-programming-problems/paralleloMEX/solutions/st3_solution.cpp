// solution_k0.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long k; // k is always 0 here
    cin >> n >> k;
    set<long long> present_values;
    for (int i = 0; i < n; ++i) {
        long long v;
        cin >> v;
        present_values.insert(v);
    }

    for (int i = 1; i <= n + 1; ++i) {
        if (present_values.find(i) == present_values.end()) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
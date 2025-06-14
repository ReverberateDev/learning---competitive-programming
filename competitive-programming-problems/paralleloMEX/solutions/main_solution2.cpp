#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    map<int, int> mp1, mp2;
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        mp1[t]++;
    }

    for(int i = 1; i <= n + 1; ++i) {
        while(mp1[i]--){
            if(k != 0){
                mp2[i % k]++;
            }
            else{
                mp2[i]++;
            }
        }
        if(k != 0){
            if(mp2[i % k] > 0){
                mp2[i % k]--;
            }
            else{
                cout << i << endl;
                return 0;
            }
        }
        else{
            if(mp2[i] > 0){
                mp2[i]--;
            }
            else{
                cout << i << endl;
                return 0;
            }
        }
    }
}
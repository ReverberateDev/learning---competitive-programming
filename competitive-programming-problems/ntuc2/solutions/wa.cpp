#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, q; cin >> n >> q;
    unordered_map<int, int> mp;
    for(int i = 0; i < n; ++i){
        int t; cin >> t;
        mp[t]++;
    }
    int ans = 0;
    for(auto [key, val] : mp){
        if(val == 2){
            ans++;
        }
    }
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int a; cin >> a;
            mp[a]++;
            if(mp[a] == 2){
                ans++;
            } 
            else if(mp[a] == 3){
                ans--;
            }
        } 
        else {
            cout << "0" << "\n";
        }
    }
}
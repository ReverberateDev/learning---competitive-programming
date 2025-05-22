#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q; cin >> q;
    vector<pair<string, int>>curr;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int tmp = 0;
            string s; cin >> s;
            int a; cin >> a;
            for(auto &[i, j] : curr){
                if(i == s){
                    j = a;
                    tmp = 1;
                }
            }
            if(!tmp){
                curr.push_back(make_pair(s, a));
            }
        }
        else{
            int cnt = 0, a; cin >> a;
            for(auto [_, i] : curr){
                if(i == a){
                    cnt++;
                }
            }
            cout << cnt << '\n';
        }
    }
}
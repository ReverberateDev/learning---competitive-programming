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
    int ans[100001];
    memset(ans, 0, sizeof(ans));
    while(q--){
        int t; cin >> t;
        if(t == 1){
            string a; cin >> a;
            int b; cin >> b;
            ans[b]++;
        }
        else{
            int a; cin >> a;
            cout << ans[a] << '\n';
        }
    }
}
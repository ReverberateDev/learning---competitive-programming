#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q; cin >> n >> q;
    vector<int> shirt(n + 1);
    iota(shirt.begin(), shirt.end(), 0);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int a, b; cin >> a >> b;
            int original = shirt[a];
            shirt[a] = b;
            for(int i = a + 1; i <= n && shirt[i] == original; i++){
                shirt[i] = b;
            }
            for(int i = a - 1; i >= 0 && shirt[i] == original; i--){
                shirt[i] = b;
            }
        }
        else{
            int a; cin >> a;
            int ans = 0;
            for(int i = 1; i <= n; i++){
                ans += (shirt[i] == a);
            }
            cout << ans << '\n';
        }
    }

}
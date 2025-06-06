#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

#ifdef DEBUG
    #define OUT(x) cerr << (#x) << '=' << (x) << endl
    #define OUT2(c) cerr << (#c) << " = {"; for (auto it = (c).begin(); it != (c).end(); ++it) cerr << (it == (c).begin() ? "" : ", ") << *it; cerr << "}" << endl;
#else
    #define OUT(x)
    #define OUT2(c)
#endif

const int inf = 1e18;

vector<vector<int>> g;
vector<int> dp, a, sm;
int ans = -inf;

void dfs1(int u, int p){
    sm[u] = a[u];
    for(int v : g[u]){
        if(v == p) continue;
        dfs1(v, u);
        sm[u] += sm[v];
        dp[u] = max(dp[u], dp[v]);
    }
    dp[u] = max(dp[u], sm[u]);
}

void dfs2(int u, int p, int out){
    ans = max(ans, dp[u] + out);
    vector<int> v_dp;
    for(int v : g[u]){
        if(v == p) continue;
        v_dp.push_back(dp[v]);
    }
    sort(v_dp.begin(), v_dp.end(), greater<int>());
    while(v_dp.size() > 2){
        v_dp.pop_back();
    }
    unordered_map<int, int> mp;
    for(int v : v_dp){
        mp[v]++;
    }
    for(int v : g[u]){
        if(v == p) continue;
        int val = dp[v];
        int n_out = out;
        for(auto it = mp.begin(); it != mp.end(); ++it){
            if(it->first == val && it->second == 1) continue;
            n_out = max(n_out, it->first);
        }
        dfs2(v, u, n_out);
    }
}

void solve() {
    int n; cin >> n;

    a.resize(n);
    dp.resize(n, -inf);
    sm.resize(n, 0);
    g.resize(n, vector<int>());

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n - 1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs1(0, -1);
    dfs2(0, -1, -inf);
    if(ans < -inf / 2) {
        cout << "Impossible\n";
    }
    else{
        cout << ans << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; tt = 1;
    while (tt--) {
        solve();
    }
}
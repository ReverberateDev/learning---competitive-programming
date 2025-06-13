#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

template<class T>
struct segmentTree {
    int n;
    vector<T> info;

    segmentTree(int _n, T _v = T()) {
        init(vector<T>(_n, _v));
    }

    segmentTree(vector<T> _vect) {
        init(_vect);
    }

    void init(vector<T> _vect) {
        n = _vect.size();
        int sz = 1 << (__lg(n - 1) + 1);
        info.assign(sz * 2, T());
        function<void(int, int, int)> build = [&](int idx, int s, int e) {
            if (s == e) {
                info[idx] = _vect[s];
                return;
            }
            int m = (s + e) / 2;
            build(2 * idx, s, m);
            build(2 * idx + 1, m + 1, e);
            info[idx] = info[2 * idx] + info[2 * idx + 1];
        };
        build(1, 0, n - 1);
    }

    T query(int idx, int s, int e, int x, int y) {
        if(s == x && e == y){
            return info[idx];
        }
        int m = (s + e) / 2;
        if(y <= m){
            return query(2 * idx, s, m, x, y);
        }
        if(x > m){
            return query(2 * idx + 1, m + 1, e, x, y);
        }
        return query(2 * idx, s, m, x, m) + query(2 * idx + 1, m + 1, e, m + 1, y);
    }

    T query(int x, int y) {
        return query(1, 0, n - 1, x, y);
    }

    void update(int idx, int s, int e, int pos, const T& val) {
        if (s == e) {
            info[idx] = val;
            return;
        }
        int m = (s + e) / 2;
        if (pos <= m) {
            update(2 * idx, s, m, pos, val);
        } 
        else {
            update(2 * idx + 1, m + 1, e, pos, val);
        }
        info[idx] = info[2 * idx] + info[2 * idx + 1];
    }

    void update(int pos, const T& val) {
        update(1, 0, n - 1, pos, val);
    }
};


struct Info{
    bool possible;
    int card;
    Info(){
        possible = false;
        card = -1;
    }
    Info(bool _possible, int _card){
        possible = _possible;
        card = _card;
    }
    Info operator+(const Info &other){
        Info res;
        res.possible = possible | other.possible;
        if(possible == 1){
            res.card = card;
        }
        else{
            res.card = other.card;
        }
        return res;
    }
};

void solve(){
    int n; cin >> n;
    vector<map<int, int>> values(3);
    vector<segmentTree<Info>> segTrees;
    for (int i = 0; i < 3; ++i) {
        segTrees.emplace_back(segmentTree<Info>(n + 1, Info()));
    }
    vector<pair<int, int>> dp(n + 1, {-1, -1});
    
    for(int i = 0; i < 3; i++){
        segTrees[i] = segmentTree<Info>(n + 1);
        for(int no = 1; no <= n; no++){
            int val; cin >> val;
            values[i][no] = val;
            Info tmp;
            if(no == n){
                tmp = Info(true, no);
            }
            else{
                tmp = Info(false, no);
            }
            segTrees[i].update(val, tmp);
        }
    }
    

    if(DEBUG){
        cout << "Testing initial segment trees\n";
        for(int i = 0; i < 3; i++){
            for(int val = 1; val <= n; val++){
                auto tmp = segTrees[i].query(val, val);
                cout << "Segment tree " << i << " val: " << val << '\n';
                cout << tmp.possible << " " << tmp.card << '\n';
            }
        }
    }
    
    
    for(int no = n - 1; no >= 1; no--){
        for(int i = 0; i < 3; i++){
            int val = values[i][no];
            if(val == 1){
                continue;
            }
            Info tmp = segTrees[i].query(1, val - 1);
            if(!tmp.possible){
                continue;
            }
            dp[no] = {tmp.card, i};
            for(int j = 0; j < 3; j++){
                val = values[j][no];
                Info tmp2 = Info(true, no);
                segTrees[j].update(val, tmp2);
            }
        }
    }
    if(DEBUG){
        cout << "outputting dp vector\n";
        for(auto [a, b] : dp){
            cout << a << " " << b << '\n';
        }
    }
    if(dp[1].first == -1 && dp[1].second == -1){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        auto func = [](pair<int, int> tmp) -> pair<char, int> {
            map<int, char> mp;
            mp[0] = 'q', mp[1] = 'k', mp[2] = 'j';
            return {mp[tmp.second], tmp.first};
        };
        vector<pair<char, int>> ans;
        int ptr = 1;
        while(ptr != n){
            ans.push_back(func(dp[ptr]));
            ptr = dp[ptr].first;
        }
        cout << ans.size() << '\n';
        for(auto [a, b] : ans){
            cout << a << " " << b << '\n';
        }
    }
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--){
        solve();
    }
}
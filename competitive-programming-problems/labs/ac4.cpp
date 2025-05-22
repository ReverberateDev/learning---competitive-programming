#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 100001;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q; cin >> q;
	vector<int>ans(MAXN, 0);
	unordered_map<string, int>mp;
	while(q--){
		int t; cin >> t;
		if(t == 1){
			string s; cin >> s;
			int i; cin >> i;
			if(mp[s] == i){
				continue;
			}
			else{
				ans[mp[s]]--;
				ans[i]++;
				mp[s] = i;
			}
		}
		else{
			int j; cin >> j;
			cout << ans[j] << '\n';
		}
	}
}

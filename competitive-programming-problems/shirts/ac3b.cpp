#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
#include <stack>
#include <utility>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <list>
#include <deque>
#include <limits>
#include <unordered_map>

using namespace std;
using ll = long long;
#define mod 998244353
#define INF 1e+16
#define rep(i, x) for(int i = 0; i < (x); i++)

using  vector2d = vector<vector<int> >;


int main(){
  int n,q;cin >> n >> q;
  set<pair<pair<ll,ll>,ll>> intervals;
  rep(i,n){
    intervals.insert({{i+1,i+2},i});
  }
  intervals.insert({{0,0},-1});
  intervals.insert({{INF,INF},-1});
  vector<int> color(n,1);
  while(q>0){
    q--;
    int query;
    cin >> query;
    if (query == 1){
      int x,c; cin >> x >> c;
      c--;
      auto itr = intervals.upper_bound({{x,INF},0});
      auto upper = *itr;
      itr--;
      itr--;
      auto lower = *itr;
      itr++;
      auto now = *itr;
      color[now.second] -= now.first.second - now.first.first;
      color[c] += now.first.second - now.first.first;
      if (c == upper.second & c == lower.second){
        intervals.erase(itr);
        intervals.erase(upper);
        intervals.erase(lower);
        intervals.insert({{lower.first.first,upper.first.second},c});
      }else if (c == upper.second){
        intervals.erase(itr);
        intervals.erase(upper);
        intervals.insert({{now.first.first,upper.first.second},c});  
      }else if(c == lower.second){
        intervals.erase(itr);
        intervals.erase(lower);
        intervals.insert({{lower.first.first,now.first.second},c});    
      }else{
        intervals.erase(itr);
        intervals.insert({now.first,c});
      }
    }else{
      int c; cin >> c;
      c--;
      cout << color[c] << endl;
    }
  }
}


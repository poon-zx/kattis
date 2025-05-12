#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <ios>
#include <iomanip>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;

using ld = long double;

constexpr int MOD = 1'000'000'007;

constexpr array<array<int, 2>, 4> directions{{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}};

// vector<vector<int>> v(3, vector<int>(4,0) 3x4 filled with 0s

void solve() {
  int n;
  ll m;
  cin>>n>>m;
  vector<pair<ll,ll>> v(n);
  ll maxx=0;
  for(int i=0;i<n;i++) {
    cin>>v[i].first>>v[i].second;
    maxx=max(maxx,(m+v[i].second)/v[i].first+1);
  }
  ll l=1,r=maxx;
  ll res=numeric_limits<ll>::max();
  while(l<=r) {
    ll mid=l+(r-l)/2;
    ll tot=0;
    for(auto &[x,y]:v) {
      ll curr=x*mid-y;
      if(curr>0) tot+=curr;
    }
    if(tot>=m) {
      res=mid;
      r=mid-1;
    } else l=mid+1;
  }
  cout<<res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tc{1};
  while (tc--) {
    solve();
  }

  return 0;
}
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
  int n,k;
  cin>>n>>k;
  vector<vector<pair<int,int>>> coord(k+1);
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      int t;
      cin>>t;
      coord[t].push_back({i,j});
    }
  }
  for (int i=1;i<=k;i++) {
    if (coord[i].empty()) {
      cout<<-1;
      return;
    }
  }
  vector<vector<int>> dp(k+1);
  dp[1].resize(coord[1].size(),0);
  for (int i=2;i<=k;i++) {
    dp[i].resize(coord[i].size(),numeric_limits<int>::max());
    for (int j=0;j<coord[i].size();j++) {
      pair<int,int> first_coord=coord[i][j];
      for (int k=0;k<dp[i-1].size();k++) {
        pair<int,int> second_coord=coord[i-1][k];
        dp[i][j]=min(dp[i][j],abs(second_coord.first-first_coord.first)+abs(second_coord.second-first_coord.second)+dp[i-1][k]);
      }
    }
  }
  int res=numeric_limits<int>::max();
  for (int i=0;i<dp[k].size();i++) {
    res=min(res,dp[k][i]);
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
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
  int n,c;
  cin>>n>>c;
  vector<pair<int,int>> v(n,pair<int,int>());
  for (int i=0;i<n;i++) {
    cin>>v[i].first;
    cin>>v[i].second;
  }
  vector<int> dp(n+1,MOD);
  dp[0]=0;
  for (int i=0;i<n;i++) {
    int w=0;
    int h=0;
    for (int j=i;j>=0;j--) {
      w+=v[j].first;
      h=max(h,v[j].second);
      if (w>c) break;
      dp[i+1]=min(dp[j]+h,dp[i+1]);
    }
  }
  cout<<dp[n];

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
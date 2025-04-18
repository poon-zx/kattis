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
  int n,m;
  cin>>n>>m;
  vector<unordered_set<int>> v(n,unordered_set<int>());
  for (int i=0;i<n;i++) {
    int a;
    cin>>a;
    for (int j=0;j<a;j++) {
      int b;
      cin>>b;
      v[i].insert(b);
    }
  }
  vector<int> notes(m);
  for (int i=0;i<m;i++) cin>>notes[i];
  vector<vector<int>> dp(n,vector<int>(m+1,MOD));
  for (int i=0;i<n;i++) dp[i][0]=0;
  for (int i=1;i<=m;i++) {
    for (int j=0;j<n;j++) {
      if (v[j].find(notes[i-1])!=v[j].end()) {
        dp[j][i]=min(dp[j][i-1],dp[j][i]);
        for (int k=0;k<n;k++) {
          if (k==j) continue;
          dp[k][i]=min(dp[j][i-1]+1,dp[k][i]);
        }
      }
    }
  }
  int res=MOD;
  for (int i=0;i<n;i++) res=min(res,dp[i][m]);
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
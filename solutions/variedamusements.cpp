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
  int n,a,b,c;
  cin>>n>>a>>b>>c;
  vector<vector<ll>> dp(n,vector<ll>(3,0));
  dp[0][0]=a;
  dp[0][1]=b;
  dp[0][2]=c;
  for (int i=1;i<n;i++) {
    dp[i][0]=(a*(dp[i-1][1]+dp[i-1][2]))%MOD;
    dp[i][1]=(b*(dp[i-1][0]+dp[i-1][2]))%MOD;
    dp[i][2]=(c*(dp[i-1][1]+dp[i-1][0]))%MOD;
  }
  cout<<(dp[n-1][0]+dp[n-1][1]+dp[n-1][2])%MOD;
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
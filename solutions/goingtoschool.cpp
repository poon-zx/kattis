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

using i64 = long long;

constexpr int MOD = 1'000'000'007;

constexpr array<array<int, 2>, 4> directions{{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}};

// vector<vector<int>> v(3, vector<int>(4,0) 3x4 filled with 0s

void solve() {
  string s;
  cin>>s;
  int res=0;
  int curr=0;
  vector<vector<int>> dp(s.size()+1, vector<int>(2, 100000));
  dp[0][0]=0;
  dp[0][1]=1;
  for (int i=0;i<s.size();i++) {
    if (s[i]=='N') {
      dp[i+1][0]=min(dp[i][0]+1, dp[i][1]+2);
      dp[i+1][1]=min(dp[i][0]+1, dp[i][1]);
    } else if (s[i]=='S') {
      dp[i+1][0]=min(dp[i][0], dp[i][1]+1);
      dp[i+1][1]=min(dp[i][0]+2, dp[i][1]+1);
    } else {
      dp[i+1][0]=min(dp[i][0]+1, dp[i][1]+2);
      dp[i+1][1]=min(dp[i][0]+2, dp[i][1]+1);
    }
  }
  cout<<min(dp[s.size()][0], dp[s.size()][1]+1);
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
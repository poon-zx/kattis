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
  cin>>n;
  vector<vector<int>> pref(n,vector<int>(8,0));
  for (int i=0;i<n;i++) {
    for (int j=0;j<8;j++) {
      cin>>pref[i][j];
    }
  }
  vector<vector<int>> dp(n+1,vector<int>(8,0));
  for (int j=0;j<8;j++) {
    dp[n][j]=j;
  }
  for (int i=n-1;i>=0;i--) {
    for (int j=0;j<8;j++) {
      int best_outcome=MOD;
      int best_combo=MOD;
      for (int k=0;k<3;k++) {
        int mask=j^(1<<k);
        int res=dp[i+1][mask];
        if (pref[i][res]<best_outcome) {
          best_outcome=pref[i][res];
          best_combo=res;
        }
      }
      dp[i][j]=best_combo;
    }
  }
  int res=dp[0][0];
  string s="";
  for (int i=2;i>=0;i--) {
    s.push_back(((res>>i)&1)?'Y':'N');
  }
  cout<<s<<"\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tc;
  cin>>tc;
  while (tc--) {
    solve();
  }

  return 0;
}
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
  int k,n;
  while (cin>>k>>n) {
    ld dp[101][10];
    for (int i=0;i<=k;i++) {
      dp[1][i]=1;
    }
    for (int i=2;i<=n;i++) {
      for (int j=0;j<=k;j++) {
        dp[i][j]=dp[i-1][j];
        if (j>0) {dp[i][j]+=dp[i-1][j-1];}
        if (j<k) {dp[i][j]+=dp[i-1][j+1];}
      }
    }
    ld tight=0;
    for (int i=0;i<=k;i++) {
      tight+=dp[n][i];
    }
    cout<<fixed<<setprecision(7)<<(tight/pow((ld)(k+1),n))*100.0<<endl;
  }
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
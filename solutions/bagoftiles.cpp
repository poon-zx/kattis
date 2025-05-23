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

// a is the number of possible draws to win,
// i.e. asking how many combinations of length n would sum up to t
// b is number of remaining combinations



void solve() {
  int g;
  cin>>g;
  ll C[31][31];
  
  for(int i = 0; i <= 30; i++){
    C[i][0] = C[i][i] = 1;
    for(int j = 1; j < i; j++){
        C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
  }

  for (int i=1;i<=g;i++) {
    int m;
    cin>>m;
    vector<int> v(m);
    for (int j=0;j<m;j++) cin>>v[j];
    int n,t;
    cin>>n>>t;
    vector<vector<ll>> dp(n+1,vector<ll>(t+1,0));
    dp[0][0]=1;
    for (int tile:v) {
      for (int j=n;j>0;j--) {
        for (int v=t;v>=tile;v--) {
          dp[j][v]+=dp[j-1][v-tile];
        }
      }
    }
    ll win=dp[n][t];
    ll total=C[m][n];
    ll lose=total-win;
    cout<<"Game "<<i<<" -- "<<win<<" : "<<lose<<"\n";
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
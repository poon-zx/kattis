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
  int n,w;
  cin>>n>>w;
  vector<vector<ll>> dp(w+2,vector<ll>(n+1,-MOD));
  vector<vector<pair<int,int>>> v(w+1,vector<pair<int,int>>());
  for (int i=0;i<=n;i++) {
    dp[w+1][i]=0;
  }
  for (int i=0;i<w+1;i++) {
    int a;
    cin>>a;
    for (int j=0;j<a;j++) {
      int b;
      cin>>b;
      v[i].push_back({b,0});
    }
    for (int j=0;j<a;j++) {
      int c;
      cin>>c;
      v[i][j].second=c;
    }
  }
  for (int i=w;i>=0;i--) {
    for (int j=n;j>=0;j--) {
      for (auto& p:v[i]) {
        int sold=min(p.second,j);
        dp[i][j]=max(dp[i][j],dp[i+1][j-sold]+p.first*(ll)sold);
      }
    }
  }
  cout<<dp[0][n]<<"\n";
  int best=INT_MAX;
  for (auto &pr:v[0]) {
    int p=pr.first;
    int sold=min(pr.second,n);
    if (dp[1][n-sold]+ll(p)*sold==dp[0][n]) best=min(best,p);
  }
  cout<<best;
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
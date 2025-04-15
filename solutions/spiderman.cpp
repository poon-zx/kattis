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
  vector<int> v(n);
  for (int i=0;i<n;i++) cin>>v[i];
  vector<vector<int>> dp(n+1,vector<int>(1001,MOD));
  dp[0][0]=0;
  vector<vector<pair<int,char>>> parent(n+1,vector<pair<int,char>>(1001,{-1,'X'}));
  for (int i=0;i<n;i++) {
    for (int j=0;j<1001;j++) {
      if (dp[i][j]==MOD) continue;
      int newH=j+v[i];
      int newMax=max(newH,dp[i][j]);
      if (newMax<dp[i+1][newH]) {
        dp[i+1][newH]=newMax;
        parent[i+1][newH]={j,'U'};
      }
      if (j>=v[i]) {
        newH=j-v[i];
        newMax=max(newH,dp[i][j]);
        if (newMax<dp[i+1][newH]) {
          dp[i+1][newH]=newMax;
          parent[i+1][newH]={j,'D'};
        }
      }
    }
  }
  if (dp[n][0]==MOD) cout<<"IMPOSSIBLE"<<"\n";
  else {
    string ans;
    int h=0;
    for (int i=n;i>0;i--) {
      pair<int,char> p=parent[i][h];
      ans.push_back(p.second);
      h=p.first;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<"\n";
  }
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
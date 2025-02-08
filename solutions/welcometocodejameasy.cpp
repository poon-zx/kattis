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

constexpr int MOD = 10000;

constexpr array<array<int, 2>, 4> directions{{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}};

// vector<vector<int>> v(3, vector<int>(4,0)) 3x4 filled with 0s

void solve() {
  int n;
  cin>>n;
  cin.ignore();
  string s="welcome to code jam";
  for (int i=0;i<n;i++) {
    vector<vector<int>> dp(20, vector<int>(31,0));
    for (int j=0;j<31;j++) {
      dp[0][j]=1;
    }
    string tc;
    getline(cin,tc);
    for (int j=1;j<20;j++) {
      for (int k=1;k<=tc.size();k++) {
        dp[j][k]=dp[j][k-1];
        if (tc[k-1]==s[j-1]) {
          // cout<<j<<" "<<k<<" "<<dp[j-1][k-1]<<" "<<dp[j][k-1];
          dp[j][k]+=dp[j-1][k-1];
        }
        dp[j][k]%=MOD;
      }
    }
    
    string res=to_string(dp[19][tc.size()]);
    while (res.size()<4) {
      res.insert(res.begin(),'0');
    }
    cout<<"Case #"<<i+1<<": "<<res<<"\n";
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
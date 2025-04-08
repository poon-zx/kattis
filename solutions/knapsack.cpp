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
#include <iomanip>
#include <ios>
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

using i64 = long long;
using namespace std;

constexpr int MOD = 1'000'000'007;

constexpr std::array<std::array<int, 2>, 4> directions{{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}};

void solve() {
  int c,n;
  while(cin>>c>>n) {
    vector<pair<int,int>> v(n);
    for (int i=0;i<n;i++) {
        int a,b;
        cin>>a>>b;
        v[i]={a,b};
    }
    vector<vector<int>> dp(n+1,vector<int>(c+1,0));
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=c;j++) {
        if (j<v[i-1].second) {
          dp[i][j]=dp[i-1][j];
          continue;
        }
        int remaining=j-v[i-1].second;
        dp[i][j]=max(dp[i-1][j],v[i-1].first+dp[i-1][remaining]);
        }
    }
    vector<int> res;
    int curr=c;
    for (int i=n;i>0;i--) {
        if (dp[i][curr]!=dp[i-1][curr]) {
        res.push_back(i-1);
        curr-=v[i-1].second;
        }
    }
    cout<<res.size()<<"\n";
    for (auto& it:res) cout<<it<<" ";
    cout<<"\n";
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
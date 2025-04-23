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
  int m;
  cin>>m;
  vector<int> sums(m);
  int maxSum=0;
  for (int i=0;i<m;i++) {
    cin>>sums[i];
    maxSum=max(maxSum,sums[i]);
  }
  vector<int> dp(maxSum+1,0);
  dp[0]=-2;
  for (int i=0;i<n;i++) {
    for (int j=0;j<=maxSum-v[i];j++) {
      if (dp[j]==0) continue;
      int add=dp[j+v[i]];
      if (add==0) {
        if (dp[j]>0||dp[j]==-2) {
          dp[j+v[i]]=i+1;
        } else dp[j+v[i]]=-1;
      } else {
        dp[j+v[i]]=-1;
      }
    }
  }
  for (int i=0;i<m;i++) {
    if (dp[sums[i]]==-1) {
      cout<<"Ambiguous"<<"\n";
    } else if (dp[sums[i]]==0) {
      cout<<"Impossible"<<"\n";
    } else {
      vector<int> res;
      int curr=sums[i];
      while(curr>0) {
        res.push_back(dp[curr]);
        curr-=v[dp[curr]-1];
      }
      sort(res.begin(),res.end());
      for (auto& ele:res) cout<<ele<<" ";
      cout<<"\n";
    }
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
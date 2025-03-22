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
  int l,w;
  cin>>l>>w;
  if (w<l||w>l*26) {
    cout<<"impossible";
    return;
  }
  vector<vector<bool>> dp(l*26+1, vector<bool>(l+1,false));
  dp[0][0]=true;
  for (int i=0;i<l;i++) {
    for (int j=0;j<=l*26;j++) {
      if (dp[j][i]) {
        for (int k=1;k<=26;k++) {
          dp[j+k][i+1]=true;
        }
      }
    }
  }
  if (!dp[w][l]) {
    cout<<"impossible";
    return;
  }
  string res="";
  int currWeight=w,currLength=l;
  while (currLength>0) {
    for (int k=1;k<=26;k++) {
      if (currWeight-k>=0&&dp[currWeight-k][currLength-1]) {
        res.push_back('a'+(k-1));
        currWeight-=k;
        currLength--;
        break;
      }
    }
  }
  cout<<res;
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
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
  int n,k;
  cin>>n>>k;
  vector<int> w(n);
  int min_w=0;
  int max_w=0;
  for (int i=0;i<n;i++) {
    cin>>w[i];
    min_w=max(min_w,w[i]);
    max_w+=w[i];
  }
  int l=min_w;
  int r=max_w;
  int res=MOD;
  while (l<=r) {
    int m=(l+r)/2;
    int boxes=1;
    int sum=0;
    for (int i=0;i<n;i++) {
      if (sum+w[i]>m) {
        boxes++;
        sum=w[i];
      } else {
        sum+=w[i];
      }
    }
    if (boxes>k) {
      l=m+1;
    } else {
      res=min(m,res);
      r=m-1;
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
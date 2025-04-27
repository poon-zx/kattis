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
  int t;
  cin>>t;
  for (int i=1;i<=t;i++) {
    vector<int> v(20);
    int w;
    cin>>w;
    for (int j=0;j<20;j++) cin>>v[j];
    int res=0;
    int k=0;
    for (int j=0;j<20;j++) {
      k=j-1;
      int curr=v[j];
      while(k>=0&&curr<v[k]) {
        v[k+1]=v[k];
        k--;
        res++;
      }
      v[k+1]=curr;
    }
    cout<<i<<" "<<res<<"\n";
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
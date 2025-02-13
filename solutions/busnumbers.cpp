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
  vector<bool> v(1001,false);
  for (int i=0;i<n;i++) {
    int t;
    cin>>t;
    v[t]=true;
  }
  int first=0;
  bool chain=false;
  for (int i=1;i<1001;i++) {
    if (!v[i]) {
      if (first!=0&&first<i-2&&chain) {
        cout<<first<<"-"<<i-1<<" ";
        first=0;
      } else if (chain&&first==i-1) {
        cout<<first<<" ";
      } else if (chain&&first==i-2) {
        cout<<first<<" "<<i-1<<" ";
      }
      chain=false;
    } else {
      if (!chain) {
        first=i;
      }
      chain=true;
    }
  }
  if (chain) {
    if (first<1001-2) {
      cout<<first<<"-"<<1000;
    } else if (first==1001-2) {
      cout<<first<<" "<<1000;
    } else {
      cout<<first;
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
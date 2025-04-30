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
  int n,m;
  cin>>n>>m;
  vector<string> v(n);
  for (int i=0;i<n;i++) {
    cin>>v[i];
  }
  vector<int> r(5);
  for (int i=0;i<n-1;i++) {
    for (int j=0;j<m-1;j++) {
      char c1=v[i][j];
      char c2=v[i][j+1];
      char c3=v[i+1][j];
      char c4=v[i+1][j+1];
      if(c1=='#'||c2=='#'||c3=='#'||c4=='#') continue;
      int res=0;
      if(c1=='X') res++;
      if(c2=='X') res++;
      if(c3=='X') res++;
      if(c4=='X') res++;
      r[res]++;
    }
  }
  for (auto& num:r) cout<<num<<"\n";
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
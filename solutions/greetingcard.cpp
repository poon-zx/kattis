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

static const int DX[12] = {
   2018, -2018,    0,    0,
   1680,  1680, -1680, -1680,
   1118,  1118, -1118, -1118
};
static const int DY[12] = {
      0,     0, 2018, -2018,
   1118, -1118,  1118, -1118,
   1680, -1680,  1680, -1680
};

void solve() {
  int n;
  cin>>n;
  unordered_set<uint64_t> s;
  vector<pair<uint64_t,uint64_t>> v(n);
  for(int i=0;i<n;i++) {
    cin>>v[i].first>>v[i].second;
    s.insert((v[i].first<<32)|v[i].second);
  }
  ll res=0;
  for(auto &[x,y]:v) {
    for(int i=0;i<12;i++) {
      uint64_t nx=x+DX[i];
      uint64_t ny=y+DY[i];
      if(s.find((nx<<32)|ny)!=s.end()) res++;
    }
  }
  cout<<res/2;
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
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
  int cs,e;
  cin>>cs>>e;
  vector<ll> v1(cs),v2(e);
  ld cs_sum=0,e_sum=0;
  for (int i=0;i<cs;i++) {
    cin>>v1[i];
    cs_sum+=(ld)v1[i];
  }
  for (int i=0;i<e;i++) {
    cin>>v2[i];
    e_sum+=(ld)v2[i];
  }
  int res=0;
  ld cs_avg=cs_sum/(ld)cs,e_avg=e_sum/(ld)e;
  for (int i=0;i<cs;i++) {
    if (((cs_sum-(ld)v1[i])/(ld)(cs-1.0)>cs_avg)&&((e_sum+(ld)v1[i])/(ld)(e+1.0)>e_avg)) res++;
  }
  cout<<res<<"\n";
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
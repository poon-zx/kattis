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
  vector<ll> papers(n+1);
  vector<double> sizes(n+1);
  for (int i=2;i<=n;i++) {
    cin>>papers[i];
    sizes[i]=pow(2,-(2.0*i-1.0)/4.0);
  }
  double tape=sizes[2];
  ll missing=max(0LL,2-papers[2]);
  for (int i=3;i<=n;i++) {
    tape+=missing*sizes[i];
    missing=max(missing*2-papers[i],0LL);
  }
  if (missing>0) cout<<"impossible";
  else cout<<fixed<<setprecision(10)<<tape;
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
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
  vector<ll> v(n+1);
  vector<ll> tot(n+1);
  for (int i=1;i<=n;i++) {
    cin>>v[i];
    tot[i]=v[i];
  }
  int m;
  cin>>m;
  for (int i=0;i<m;i++) {
    int a,b;
    cin>>a>>b;
    tot[a]+=v[b];
    tot[b]+=v[a];
  }
  ll minn=numeric_limits<ll>::max();
  int best=0;
  for (int i=1;i<=n;i++) {
    if (tot[i]<minn) {
      minn=tot[i];
      best=i;
    }
  }
  cout<<best;
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
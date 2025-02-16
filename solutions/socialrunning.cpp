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
  vector<int> v;
  for (int i=0;i<n;i++) {
    int t;
    cin>>t;
    v.push_back(t);
  }
  if (n==2) {
    cout<<2*min(v[0],v[1]);
    return;
  }
  ll minn=MOD;
  for (int i=0;i<n;i++) {
    ll curr;
    if (i==0) {
      curr=v[n-2];
    } else if (i==1) {
      curr=v[n-1];
    } else {
      curr=v[i-2];
    }
    minn=min(minn,curr+v[i]);
  }
  cout<<minn;
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
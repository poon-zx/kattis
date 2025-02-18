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
  vector<ll> coeff(n+1);
  for (int i=0;i<n+1;i++) {
    cin>>coeff[i];
  }
  vector<ll> p(n+1,0);
  for (int x=0;x<=n;x++) {
    ll value=0;
    ll power=1;
    for (int j=n;j>=0;j--) {
      value+=coeff[j]*power;
      power*=x;
    }
    p[x]=value;
  }
  vector<ll> C(n+1);
  C[0]=p[0];
  vector<ll> diff=p;
  for (int level=1;level<=n;level++) {
    for (int i=0;i<n+1-level;i++) {
      diff[i]=diff[i+1]-diff[i];
    }
    C[level]=diff[0];
  }
  for (int i=0;i<=n;i++) {
    cout<<C[i]<<" ";
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
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
  ll n,m,a,c,x;
  cin>>n>>m>>a>>c>>x;
  vector<ll> v(n);
  for (int i=0;i<n;i++) {
    x=(a*x+c)%m;
    v[i]=x;
  }
  int res=0;
  for (int i=0;i<n;i++) {
    int l=0,r=n-1;
    bool found=false;
    while(l<=r) {
      int mid=l+(r-l)/2;
      if(v[mid]==v[i]) {
        found=true;
        break;
      } else if (v[mid]>v[i]) r=mid-1;
      else l=mid+1;
    }
    if(found) res++;
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
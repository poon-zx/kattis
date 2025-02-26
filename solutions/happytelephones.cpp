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
  while (cin>>n>>m&&n!=0) {
    vector<pair<ll,ll>> v(n);
    for (int i=0;i<n;i++) {
      ll a,b,c,d;
      cin>>a>>b>>c>>d;
      v[i]={c,c+d};
    }

    for (int i=0;i<m;i++) {
      int res=0;
      ll start,dur;
      cin>>start>>dur;
      ll end=start+dur;
      for (int j=0;j<n;j++) {
        if (start>=v[j].second||end<=v[j].first) {
          continue;
        } else {
          res++;
        }
      }
      cout<<res<<"\n";
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
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
  ll n;
  cin>>n;
  ll best_d=numeric_limits<ll>::max();
  int best_x=0,best_y=0;
  for (int x=0;x<=n+1;x++) {
    int y;
    if (x>n) {
      y=0;
    } else {
      y=(int)sqrt(n*n-(ll)x*(ll)x)+1;
    }
    ll d=(ll)x*(ll)x+(ll)y*(ll)y;
    if (d<best_d&&d>n*n) {
      best_d=d;
      best_x=x;
      best_y=y;
    }
  }
  cout<<best_x<<" "<<best_y;
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
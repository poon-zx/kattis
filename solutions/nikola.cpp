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

vector<vector<ll>> cache(1001,vector<ll>(1001,-1));
int n;
vector<int> cost;

ll dp(int space, int last) {
  if (space==n) {
    return cost[space];
  } else if (space>n||space<=0) {
    return 1e9;
  } else {
    if (cache[space][last]!=-1) return cache[space][last];
    else {
      ll forward=dp(space+last+1,last+1)+cost[space];
      ll backward=dp(space-last,last)+cost[space];
      cache[space][last]=min(forward,backward);
      return cache[space][last];
    }
  }
};

// vector<vector<int>> v(3, vector<int>(4,0) 3x4 filled with 0s

void solve() {
  cin>>n;
  cost.resize(n+1);
  for (int i=1;i<=n;i++) cin>>cost[i];
  cout<<dp(2,1);
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
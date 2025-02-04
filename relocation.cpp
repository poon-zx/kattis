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
#include <iomanip>
#include <ios>
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

using i64 = long long;

constexpr int MOD = 1'000'000'007;

constexpr std::array<std::array<int, 2>, 4> directions{{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}};

void solve() {
  int n,q;
  std::cin >> n >> q;
  int p[n+1];
  for (int i = 1; i <= n; i++) {
    int c;
    std::cin >> c;
    p[i] = c;
  }
  for (int i = 0; i < q; i++) {
    int pos,first,second;
    std::cin >> pos >> first >> second;
    if (pos == 1) {
      p[first] = second;
    } else {
      int r;
      r = std::abs(p[first] - p[second]);
      std::cout << r << "\n";
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tc{1};
  while (tc--) {
    solve();
  }

  return 0;
}
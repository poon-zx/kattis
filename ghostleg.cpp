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
  int n, m;
  std::cin >> n >> m;
  int rung[m];
  int res[n];
  for (int i = 0; i < m; i++) {
    int x;
    std::cin >> x;
    rung[i] = x-1;
  }
  for (int i = 0; i < n; i++) {
    int curr = i;
    for (int j = 0; j < m; j++) {
      if (curr == rung[j]) {
        curr++;
      } else if (curr-1 == rung[j]) {
        curr--;
      }
    }
    res[curr] = i+1;
  }
  for (int i = 0; i < n; i++) {
    std::cout << res[i] << "\n";
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
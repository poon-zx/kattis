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
  int i;
  std::cin >> i;
  int a[i][3];
  for (int j = 0; j < 3; j++) {
    for (int k = 0; k < i; k++) {
      int x;
      std::cin >> x;
      a[k][j] = x;
    }
  }

  for (int j = 0; j < i; j++) {
    int temp[3] = {a[j][0], a[j][1], a[j][2]};
    std::sort(std::begin(temp), std::end(temp));
    std::cout << temp[1];
    if (j < i - 1) {
      std::cout << " ";
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
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
  std::string s;
  double c;
  std::cin >> s >> c;
  if (s.size() < c) {
    std::cout << s.size();
  } else {
    std::cout << std::setprecision(16) << c;
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
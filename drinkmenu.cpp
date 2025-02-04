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
  std::cin.ignore();
  std::unordered_map<std::string, int> ht;
  std::string menu[n];
  for (int i = 0; i < n; i++) {
    std::string drink;
    std::getline(std::cin, drink);
    menu[i] = drink;
  }
  for (int i = 0; i < m; i++) {
    std::string person;
    std::cin >> person;
    if (ht.find(person) == ht.end()) {
      ht[person] = 1;
      std::cout << menu[0] << "\n";
    } else {
      std::cout << menu[ht[person]] << "\n";
      ht[person]++;
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
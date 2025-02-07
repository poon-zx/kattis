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

using i64 = long long;

constexpr int MOD = 1'000'000'007;

constexpr array<array<int, 2>, 4> directions{{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}};

void solve() {
  int i;
  int counter = 1;
  while (cin >> i) {
    if (i==0) {break;}
    string v[i];
    string s;
    for (int a = 0; a < i; a++) {
      cin >> s;
      v[a] = s;
    }
    int l = 0;
    cout << "SET " << counter << "\n";
    while (l<i) {
      cout << v[l] << "\n";
      l+=2;
    }
    l = (i % 2 == 0)?i-1:i-2;
    while (l>=0) {
      cout << v[l] << "\n";
      l-=2;
    }
    counter++;
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
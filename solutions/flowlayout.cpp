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
  int m;
  while (cin >> m) {
    if (m==0) {return;}
    int w, h, a, b,running_w,running_h;
    w = 0, h = 0, running_w=0,running_h=0;
    while (cin >> a >> b) {
      if (a==-1) {break;}
      if (running_w+a>m) {
        w=max(w,running_w);
        running_w=a;
        h+=running_h;
        running_h=b;
      } else {
        running_w+=a;
        running_h=max(running_h,b);
      }
    }
    w=max(w,running_w);
    h+=running_h;
    cout << w << " x " << h << "\n";
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
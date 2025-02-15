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
  int h,w,b;
  cin>>h>>w>>b;
  int lvl=1;
  int curr=0;
  for (int i=0;i<b;i++) {
    if (lvl==h+1) {
      cout<<"YES";
      return;
    }
    int c;
    cin>>c;
    if (curr+c>w) {
      cout<<"NO";
      return;
    } else if (curr+c==w) {
      lvl++;
      curr=0;
    } else {
      curr+=c;
    }
  }
  if (lvl==h+1) {cout<<"YES";}
  else {cout<<"NO";}
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
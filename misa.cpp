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

using namespace std;

using i64 = long long;

constexpr int MOD = 1'000'000'007;

constexpr array<array<int, 2>, 8> directions{{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
    {1, 1},
    {1, -1},
    {-1, 1},
    {-1, -1}
}};

void solve() {
  int r,c;
  cin>>r>>c;
  int res=0;
  int misa=0;
  vector<vector<char>> v(r, vector<char>(c));
  for (int i=0;i<r;i++) {
    for (int j=0;j<c;j++) {
      cin>>v[i][j];
    }
  }
  for (int i=0;i<r;i++) {
    for (int j=0;j<c;j++) {
      int curr=0;
      for (auto &dir:directions) {
        int new_r=i+dir[0];
        int new_c=j+dir[1];
        if (new_r>=0 && new_r<r && new_c>=0 && new_c<c && v[new_r][new_c]=='o') {
          if (v[i][j]=='o') {
            res++;
          } else {
            curr++;
          }
        }
      }
      misa=max(misa,curr);
    }
  }
  int f=res/2+misa;
  cout<<f;
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
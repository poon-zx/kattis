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

// vector<vector<int>> v(3, vector<int>(4,0) 3x4 filled with 0s

vector<vector<char>> dfs(vector<vector<char>> v, int r, int c) {
  v[r][c]='.';
  for (auto [i,j]:directions) {
    int new_x=r+i;
    int new_y=c+j;
    if (new_x>=0&&new_x<v.size()&&new_y>=0&&new_y<v[0].size()&&v[new_x][new_y]=='#') {
      v=dfs(v,new_x,new_y);
    }
  }
  return v;
};

void solve() {
  int r,c;
  cin>>r>>c;
  vector<vector<char>> v(r, vector<char>(c,'a'));
  for (int i=0;i<r;i++) {
    for (int j=0;j<c;j++) {
      cin>>v[i][j];
    }
  }
  ll res=0;
  for (int i=0;i<r;i++) {
    for (int j=0;j<c;j++) {
      if (v[i][j]=='#') {
        v=dfs(v,i,j);
        res++;
      }
    }
  }
  cout<<res;

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
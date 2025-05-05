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
  int n,m;
  cin>>n>>m;
  vector<vector<int>> v(n,vector<int>(m,0));
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) cin>>v[i][j];
  }
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      int res=0;
      for(auto &[x,y]:directions) {
        int new_x=i+x,new_y=j+y;
        if(new_x>=0&&new_x<n&&new_y>=0&&new_y<m) {
          if(v[i][j]<v[new_x][new_y]) res++;
        }
      }
      if(res==4) {cout<<"Jebb";return;}
    }
  }
  cout<<"Neibb";
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
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
  int n;
  cin>>n;
  cin.ignore();
  vector<string> grid;
  for (int i=0;i<n;i++) {
    string s;
    getline(cin,s);
    grid.push_back(s);
  }
  vector<vector<int>> safe;
  vector<vector<int>> spy;
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      if (grid[i][j]=='H') {
        safe.push_back({i,j});
      } else if (grid[i][j]=='S') {
        spy.push_back({i,j});
      }
    }
  }
  int maxi=0;
  for (auto &s:spy) {
    int closest=MOD;
    for (auto &sa:safe) {
      closest=min(closest,abs(sa[1]-s[1])+abs(sa[0]-s[0]));
    }
    maxi=max(maxi,closest);
  }
  cout<<maxi;

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
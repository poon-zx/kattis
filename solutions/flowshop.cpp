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

using i64 = long long;

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
  vector<vector<int>> v;
  for (int i=0;i<n;i++) {
    vector<int> curr;
    for (int j=0;j<m;j++) {
      int t;
      cin>>t;
      curr.push_back(t);
    }
    v.push_back(curr);
  }
  vector<vector<int>> r;
  for (int i=0;i<n;i++) {
    vector<int> curr;
    int temp=0;
    for (int j=0;j<m;j++) {
      if (i>0) {
        if (temp<r[i-1][j]) {
          temp+=(r[i-1][j]-temp+v[i][j]);
        } else {
          temp+=v[i][j];
        }
        curr.push_back(temp);
      } else {
        temp+=v[i][j];
        curr.push_back(temp);
      }
    }
    r.push_back(curr);
  }
  for (int i=0;i<n;i++) {
    cout<<r[i][m-1];
    if (i<n-1) {
      cout<<" ";
    }
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
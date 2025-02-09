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

bool is_square(vector<i64> p1,vector<i64> p2,vector<i64> p3,vector<i64> p4) {
  vector<i64> dists;
  vector<vector<i64>> points={p1,p2,p3,p4};
  for (int i=0;i<4;i++) {
    for (int j=i+1;j<4;j++) {
      i64 dx=points[i][0]-points[j][0];
      i64 dy=points[i][1]-points[j][1];
      dists.push_back(dx*dx+dy*dy);
    }
  }
  sort(dists.begin(),dists.end());
  return (dists[0] == dists[1] && dists[1] == dists[2] && dists[2] == dists[3] &&
            dists[4] == dists[5] && dists[3] * 2 == dists[4]);
}

void solve() {
  i64 x,y;
  vector<vector<i64>> v;
  for (int i=0;i<3;i++) {
    cin>>x>>y;
    v.push_back({x,y});
  }
  vector<i64> d1={v[0][0]+v[1][0]-v[2][0],v[0][1]+v[1][1]-v[2][1]};
  vector<i64> d2={v[0][0]+v[2][0]-v[1][0],v[0][1]+v[2][1]-v[1][1]};
  vector<i64> d3={v[2][0]+v[1][0]-v[0][0],v[2][1]+v[1][1]-v[0][1]};
  
  if (is_square(v[0], v[1], v[2], d1)) {
    cout << d1[0] << " " << d1[1];
  } else if (is_square(v[0], v[1], v[2], d2)) {
    cout << d2[0] << " " << d2[1];
  } else {
    cout << d3[0] << " " << d3[1];
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
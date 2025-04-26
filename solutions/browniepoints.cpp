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

struct point_i {
  int x, y;                                      // use this if possible
  point_i() { x = y = 0; }                       // default constructor
  point_i(int _x, int _y) : x(_x), y(_y) {}      // constructor
};

void solve() {
  int n;
  while(cin>>n&&n!=0) {
    vector<point_i> v(n);
    for (int i=0;i<n;i++) {
      int a,b;
      cin>>a>>b;
      v[i]=point_i(a,b);
    }
    point_i mid=v[n/2];
    int stan=0,ollie=0;
    for (int i=0;i<n;i++) {
      point_i curr=v[i];
      if((curr.x>mid.x&&curr.y>mid.y)||(curr.x<mid.x&&curr.y<mid.y)) stan++;
      else if ((curr.x<mid.x&&curr.y>mid.y)||(curr.x>mid.x&&curr.y<mid.y)) ollie++;
    }
    cout<<stan<<" "<<ollie<<endl;
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
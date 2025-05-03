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
  unordered_map<int, double> dice = {
        {2,  1.0/36},
        {3,  2.0/36},
        {4,  3.0/36},
        {5,  4.0/36},
        {6,  5.0/36},
        {7,  6.0/36},
        {8,  5.0/36},
        {9,  4.0/36},
        {10, 3.0/36},
        {11, 2.0/36},
        {12, 1.0/36}
    };
  int n;
  cin>>n;
  double res=0.0;
  while(n--) {
    int c;
    cin>>c;
    res+=dice[c];
  }
  cout<<fixed<<setprecision(4)<<res;
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
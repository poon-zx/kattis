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
  string time1,time2;
  cin>>time1>>time2;
  int h1,h2,m1,m2;
  h1=stoi(time1.substr(0,2));
  h2=stoi(time2.substr(0,2));
  m1=stoi(time1.substr(3,2));
  m2=stoi(time2.substr(3,2));
  int res=0;
  if (h2<h1||(h2==h1&&m2<m1)) {
    res+=h2*60+m2;
    res+=(24-h1-1)*60+(60-m1);
  } else if (h1==h2) {
    res+=m2-m1;
  } else {
    res+=(h2-h1-1)*60+m2+(60-m1);
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
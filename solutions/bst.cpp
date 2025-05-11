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
  vector<int> depths(n+1,0);
  set<int> s;
  ll res=0;
  while(n--) {
    int a;
    cin>>a;
    int prev_depth=-1,suc_depth=-1;
    auto it=s.lower_bound(a);
    if(it!=s.begin()) {
      auto prev_it=prev(it);
      prev_depth=depths[*prev_it];
    }
    if(it!=s.end()) {
      suc_depth=depths[*it];
    }
    depths[a]+=max(prev_depth,suc_depth)+1;
    res+=depths[a];
    s.insert(it,a);
    cout<<res<<"\n";
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
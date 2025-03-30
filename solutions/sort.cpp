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
  int n,c;
  cin>>n>>c;
  unordered_map<int,pair<int,int>> map;
  for (int i=0;i<n;i++) {
    int t;
    cin>>t;
    if (map.find(t)==map.end()) map[t]={0,-i};
    map[t].first++;
  }
  vector<vector<int>> v;
  for (auto& it:map) {
    v.push_back({it.second.first,it.second.second,it.first});
  }
  sort(v.begin(),v.end(),greater<vector<int>>());
  for (auto& it:v) {
    for (int i=0;i<it[0];i++) {
      cout<<it[2]<<" ";
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
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
  string s;
  cin>>n;
  unordered_map<string,int> map1;
  unordered_map<string,int> map2;
  for (int i=0;i<n;i++) {
    cin>>s;
    if (map1.find(s)==map1.end()) map1[s]=0;
    map1[s]++;
  }
  for (int i=0;i<n;i++) {
    cin>>s;
    if (map2.find(s)==map2.end()) map2[s]=0;
    map2[s]++;
  }
  int res=0;
  for (auto& it:map1) {
    if (map2.find(it.first)!=map2.end()) {
      res+=min(map2[it.first],it.second);
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
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
  unordered_map<char, string> map;
  unordered_map<string, char> map2;
  string s,t;
  getline(cin,s);
  for (char c:s) {
    if (!(cin>>t)) {
      cout<<"False";
      return;
    }
    if (map.find(c)!=map.end()) {
      if (map[c]!=t) {
        cout<<"False";
        return;
      }
    }
    if (map2.find(t)!=map2.end()) {
      if (map2[t]!=c) {
        cout<<"False";
        return;
      }
    }
    map[c]=t;
    map2[t]=c;
  }
  if (cin>>t) {cout<<"False";}
  else cout<<"True";
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
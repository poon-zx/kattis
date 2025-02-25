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
  string s;
  unordered_map<string,int> m;
  while (true) {
    getline(cin,s);
    if (s=="***") {break;}
    if (m.find(s)==m.end()) {m[s]=0;}
    m[s]++;
  }
  int maxx=0;
  string name;
  bool two=false;
  for (auto it:m) {
    if (it.second>maxx) {
      maxx=it.second;
      name=it.first;
      two=false;
    } else if (it.second==maxx) {
      two=true;
    }
  }
  if (two) {cout<<"Runoff!";}
  else {cout<<name;}
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
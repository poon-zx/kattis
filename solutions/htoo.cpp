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

unordered_map<char, ll> parse_mole(string s) {
  unordered_map<char, ll> map;
  int n=s.size();
  int i=0;
  while (i<n) {
    char atom=s[i];
    i++;
    ll count=0;
    while (i<n&&isdigit(s[i])) {
      count=count*10+(s[i]-'0');
      i++;
    }
    if (count==0) count=1;
    map[atom]+=count;
  }
  return map;
}

void solve() {
  string s1, s2;
  ll k;
  cin>>s1>>k>>s2;
  unordered_map<char,ll> map1=parse_mole(s1);
  unordered_map<char,ll> map2=parse_mole(s2);
  ll res=numeric_limits<ll>::max();
  for (auto& it:map2) {
    if (map1.find(it.first)==map1.end()) {
      cout<<0;
      return;
    }
    res=min(res,(map1[it.first]*k)/it.second);
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
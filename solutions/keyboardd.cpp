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
  string s1,s2;
  getline(cin,s1);
  getline(cin,s2);
  vector<int> v1(26,0);
  vector<int> v2(26,0);
  int space1=0,space2=0;
  for (int i=0;i<s1.size();i++) {
    if (s1[i]==' ') {
      space1++;
    } else {
      v1[s1[i]-'a']++;
    }
  }
  for (int i=0;i<s2.size();i++) {
    if (s2[i]==' ') {
      space2++;
    } else {
      v2[s2[i]-'a']++;
    }
  }
  if (space2>space1) cout<<' ';
  for (int i=0;i<26;i++) {
    if (v2[i]>v1[i]) cout<<(char)(i+'a');
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
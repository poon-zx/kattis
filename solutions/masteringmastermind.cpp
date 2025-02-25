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
  string s1;
  string s2;
  cin>>n>>s1>>s2;
  vector<int> v1(26);
  vector<int> v2(26);
  int r=0,s=0;
  for (int i=0;i<n;i++) {
    if (s1[i]==s2[i]) {
      r++;
    } else {
      v1[s1[i]-'A']++;
      v2[s2[i]-'A']++;
    }
  }
  for (int i=0;i<26;i++) {
    s+=min(v1[i],v2[i]);
  }
  cout<<r<<" "<<s;
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
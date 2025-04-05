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
  getline(cin,s);
  int res=0;
  vector<int> v;
  for (int i=0;i<s.size()-1;i++) {
    if (s[i]==':'&&s[i+1]==')') v.push_back(i);
    else if (s[i]==';'&&s[i+1]==')') v.push_back(i);
  }
  for (int i=0;i<s.size()-2;i++) {
    if (s[i]==':'&&s[i+1]=='-'&&s[i+2]==')') v.push_back(i);
    else if (s[i]==';'&&s[i+1]=='-'&&s[i+2]==')') v.push_back(i);
  }
  sort(v.begin(),v.end());
  for (auto& it:v) cout<<it<<"\n";
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
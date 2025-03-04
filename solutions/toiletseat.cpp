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
  cin>>s;
  ll res1=0,res2=0,res3=0;
  for (int i=1;i<s.size();i++) {
    if (i==1) {
      if (s[i]=='D'&&s[0]=='D') {
        res1++;
      } else if (s[i]=='D'&&s[0]=='U') {
        res1+=2;
        res2++;
        res3++;
      } else if (s[i]=='U'&&s[0]=='U') {
        res2++;
      } else {
        res1++;
        res2+=2;
        res3++;
      }
    } else {
      res1+=(s[i]=='U')?0:2;
      res2+=(s[i]=='D')?0:2;
      res3+=(s[i]==s[i-1])?0:1;
    }
  }
  cout<<res1<<"\n"<<res2<<"\n"<<res3;
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
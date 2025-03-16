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

// Helper function to convert __int128 to string
string toString(__int128 n) {
    if (n == 0) return "0";
    bool neg = n < 0;
    if (neg) n = -n;
    string s;
    while (n > 0) {
        s.push_back('0' + (n % 10));
        n /= 10;
    }
    if (neg) s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
}

// Helper function to convert string to __int128
__int128 toInt128(const string &s) {
    __int128 res = 0;
    for (char c : s) {
        res = res * 10 + (c - '0');
    }
    return res;
}

void solve() {
  string s;
  while (cin>>s&&s!="0") {
    __int128 num=toInt128(s)-1;
    vector<__int128> subset;
    __int128 power=1;
    while (num>0) {
      if (num%2==1) {
        subset.push_back(power);
      }
      num/=2;
      power*=3;
    }
    cout<<"{";
    if (subset.empty()) cout<<" }";
    else {
      cout<<" ";
      for (int i=0;i<subset.size();i++) {
        cout<<toString(subset[i]);
        if (i!=subset.size()-1) cout<<", ";
        else cout<<" ";
      }
      cout<<"}";
    }
    cout<<"\n";
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
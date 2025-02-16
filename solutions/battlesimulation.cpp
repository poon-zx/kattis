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
  string res;
  for (auto &ch:s) {
    if (ch=='R') {res.push_back('S');}
    else if (ch=='B') {res.push_back('K');}
    else {res.push_back('H');}
    if (res.size()>=3) {
      string c=res.substr(res.size()-3);
      unordered_set<string> se={"SKH","SHK","HSK","HKS","KHS","KSH"};
      if (se.find(c)!=se.end()) {
        res.erase(res.end()-3,res.end());
        res.push_back('C');
      }
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
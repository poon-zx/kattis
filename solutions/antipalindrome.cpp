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

using i64 = long long;

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
  string new_s;
  for (auto &ch:s) {
    if (!isalpha(ch)) {
      continue;
    }
    ch=tolower(ch);
    new_s+=ch;
  }
  bool pali=false;
  for (int i=0;i<new_s.size()-1;i++) {
    if (new_s[i]==new_s[i+1]) {
      pali=true;
    } else if (i<new_s.size()-2&&new_s[i]==new_s[i+2]) {
      pali=true;
    }
  }
  if (pali) {cout<<"Palindrome";}
  else {cout<<"Anti-palindrome";}
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
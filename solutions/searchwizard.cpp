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

std::vector<int> kmp_search(const std::string &text, const std::string &pattern) {
    int n = text.size(), m = pattern.size();
    if (m == 0) return {};                   // no pattern → no matches
    // build “failure” table
    std::vector<int> b(m+1);
    b[0] = -1;
    int i = 0, j = -1;
    while (i < m) {
        while (j >= 0 && pattern[i] != pattern[j]) j = b[j];
        ++i; ++j;
        b[i] = j;
    }
    // search
    std::vector<int> matches;
    i = 0; j = 0;
    while (i < n) {
        while (j >= 0 && text[i] != pattern[j]) j = b[j];
        ++i; ++j;
        if (j == m) {
            matches.push_back(i - j);
            j = b[j];
        }
    }
    return matches;
}

void solve() {
  string s;
  int n;
  string line;
  cin>>s>>n;
  cin.ignore();
  getline(cin,line);
  cout<<kmp_search(line,s).size();
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
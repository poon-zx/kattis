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
  stack<char> stack;
  for (char c:s) {
    if (c=='p'||c=='g'||c=='o') {
      stack.push(c);
    } else if (c=='P'||c=='G'||c=='O') {
      char bad;
      if (c=='P') bad='p';
      else if (c=='G') bad='g';
      else bad='o';
      while (!stack.empty()&&stack.top()!=bad) {
        stack.pop();
      }
      if (stack.empty()) {
        cout<<"Neibb";
        return;
      }
      stack.pop();
    }
  }
  vector<int> v(3);
  while (!stack.empty()) {
    char c=stack.top();
    if (c=='p') v[0]++;
    else if (c=='g') v[1]++;
    else v[2]++;
    stack.pop();
  }
  for (auto& ele:v) cout<<ele<<"\n";
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
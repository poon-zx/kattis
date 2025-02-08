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

int minimum=MOD;
void combinations(deque<vector<int>> q,int sour,int bitter) {
    if (q.empty()) {
      if (sour>0&&bitter>0) {
        minimum=min(minimum, abs(sour-bitter));
      }
      return;
    }
    vector<int> curr=q.front();
    q.pop_front();
    combinations(q,sour,bitter);
    combinations(q,sour*curr[0],bitter+curr[1]);
  }

void solve() {
  int n,a,b;
  cin>>n;
  deque<vector<int>> v;
  for (int i=0;i<n;i++) {
    cin>>a>>b;
    v.push_back({a,b});
  }
  
  combinations(v,1,0);
  cout<<minimum;
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
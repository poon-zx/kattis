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

constexpr i64 MOD = 1'000'000'007;

constexpr array<array<int, 2>, 4> directions{{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}};

// vector<vector<int>> v(3, vector<int>(4,0) 3x4 filled with 0s

void solve() {
  // SSSP
  int f,s,g,u,d;
  cin>>f>>s>>g>>u>>d;
  vector<i64> v(f+1,MOD);
  v[s]=0;
  deque<i64> q;
  q.push_back(s);
  while (!q.empty()) {
    int curr=q.front();
    q.pop_front();
    if (curr+u<=f&&v[curr]+1<v[curr+u]) {
      v[curr+u]=v[curr]+1;
      q.push_back(curr+u);
    }
    if (curr-d>0&&v[curr]+1<v[curr-d]) {
      v[curr-d]=v[curr]+1;
      q.push_back(curr-d);
    }
  }
  if (v[g]==MOD) {
    cout<<"use the stairs";
  } else {cout<<v[g];}
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
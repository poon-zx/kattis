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

vector<vector<int>> v={{},{2,4},{3,5},{6},{5,7},{6,8},{9},{8},{9,0},{}};
unordered_set<int> sett;

void backtracking(int num, int curr) {
  if ((num>=100&&num<1000)||(num==0&&curr==0)) {
    sett.insert(num);
    return;
  }
  if (v[curr].empty()) sett.insert(num);
  else {
    for (int i=0;i<v[curr].size();i++) {
      backtracking(num*10+v[curr][i],v[curr][i]);
      backtracking(num,v[curr][i]);
    }
  }
  backtracking(num*10+curr,curr);
}

void solve() {
  int n;
  cin>>n;
  backtracking(0,1);
  int res=10000;
  for (auto& num:sett) {
    if (abs(n-num)<abs(n-res)) {
      res=num;
    }
  }
  cout<<res<<"\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tc;
  cin>>tc;
  while (tc--) {
    solve();
  }

  return 0;
}
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
  int n,m;
  cin>>n>>m;
  vector<vector<char>> v(n,vector<char>(m));
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cin>>v[i][j];
    }
  }
  vector<int> cnt(m);
  for(int j=0;j<m;j++) {
    int curr=0;
    for(int i=0;i<n;i++) {
      if(v[i][j]=='S') curr++;
    }
    cnt[j]=curr;
  }
  vector<vector<char>> res(n,vector<char>(m));
  for(int j=0;j<m;j++) {
    int curr=cnt[j];
    for(int i=n-1;i>=0;i--) {
      if(curr>0) res[i][j]='S';
      else res[i][j]='.';
      curr--;
    }
  }
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cout<<res[i][j];
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
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
  int n,x;
  cin>>n>>x;
  vector<int> paint(n);
  for (int i=0;i<n;i++) {
    cin>>paint[i];
  }
  sort(paint.begin(),paint.end());
  ll waste=0;
  for (int i=0;i<x;i++) {
    int find;
    cin>>find;
    // bin search
    int l=0;
    int r=paint.size()-1;
    int lowest=MOD;
    while (l<=r) {
      int m=l+(r-l)/2;
      //cout<<paint[m]<<" "<<find<<" ";
      if (paint[m]<find) {l=m+1;}
      else {
        r=m-1;
        lowest=min(lowest,m);
      }
    }
    //cout<<lowest<<" ";
    waste+=paint[lowest]-find;
  }
  cout<<waste;
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
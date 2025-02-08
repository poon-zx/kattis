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
  int n;
  cin>>n;
  unordered_map<int,int> umap={
    {1,-2},
    {2,-2},
    {3,-2},
    {4,-2},
    {5,-2},
    {6,-2},
  };
  unordered_map<int,int> ht;
  for (int i=0;i<n;i++) {
    int s;
    cin>>s;
    if (umap[s]==-2) {
      umap[s]=i;
    } else {
      umap[s]=-1;
    }
  }
  for (int i=6;i>0;i--) {
    if (umap[i]>=0) {
      cout<<umap[i]+1;
      return;
    }
  }
  cout<<"none";
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
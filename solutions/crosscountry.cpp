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
  int n,s,t;
  cin>>n>>s>>t;
  vector<tuple<int,int,int>> edges;
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      int a;
      cin>>a;
      if(i==j) continue;
      edges.push_back({i,j,a});
    }
  }
  vector<int> dist(n,numeric_limits<int>::max());
  dist[s]=0;
  for(int i=0;i<n-1;i++) {
    bool modified=false;
    for (auto& [u,v,w] : edges) {
      if (dist[u] != numeric_limits<int>::max() && dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        modified = true;
      }
    }
    if (!modified) break;
  }
  cout<<dist[t];
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
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
  int n,h,l;
  cin>>n>>h>>l;
  vector<int> dist(n,numeric_limits<int>::max());
  deque<int> q;
  for(int i=0;i<h;i++) {
    int a;
    cin>>a;
    q.push_back(a);
    dist[a]=0;
  }
  vector<vector<int>> adjList(n,vector<int>());
  for(int i=0;i<l;i++) {
    int b,c;
    cin>>b>>c;
    adjList[b].push_back(c);
    adjList[c].push_back(b);
  }
  while(!q.empty()) {
    int top=q.front();
    q.pop_front();
    for(auto &v:adjList[top]) {
      if(dist[v]>dist[top]+1) {
        dist[v]=dist[top]+1;
        q.push_back(v);
      }
    }
  }
  int maxx=0;
  int res=0;
  for(int i=0;i<n;i++) {
    if(dist[i]>maxx) {
      maxx=dist[i];
      res=i;
    }
  }
  cout<<res;
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
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

typedef vector<int> vi;
vi dfs_num, dfs_low, dfs_parent, articulation_vertex;
vector<pair<int,int>> bridges;
int dfsNumberCounter, dfsRoot, rootChildren;

void articulationPointAndBridge(int u, vector<vector<int>> &adjList) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;  // dfs_low[u]<=dfs_num[u]
  for (auto &v : adjList[u]) {
    if (dfs_num[v] == -1) {               // a tree edge
      dfs_parent[v] = u;
      if (u == dfsRoot) ++rootChildren;          // special case, root

      articulationPointAndBridge(v,adjList);

      if (dfs_low[v] >= dfs_num[u])              // for articulation point
        articulation_vertex[u] = 1;              // store this info first
      if (dfs_low[v] > dfs_num[u]) {
        bridges.emplace_back(u, v);
      }               // for bridge
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);  // subtree, always update
    }
    else if (v != dfs_parent[u])                 // if a non-trivial cycle
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);  // then can update
  }
}

void solve() {
  int p,c;
  while(cin>>p>>c&&(p!=0)) {
    vector<vi> adjList(p);
    for(int i=0;i<c;i++) {
      int a,b;
      cin>>a>>b;
      adjList[a].push_back(b);
      adjList[b].push_back(a);
    }
    dfs_num.assign(p, -1); dfs_low.assign(p, 0);
    dfs_parent.assign(p, -1); articulation_vertex.assign(p, 0);
    bridges.clear();
    dfsNumberCounter = 0;
    for(int u=0;u<p;u++) {
      if(dfs_num[u]==-1) {
        dfsRoot=u;
        rootChildren=0;
        articulationPointAndBridge(u,adjList);
        articulation_vertex[dfsRoot]=(rootChildren>1);
      }
    }
    if(!bridges.empty()) cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";
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
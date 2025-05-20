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
  int n,m,q,s;
  while(cin>>n>>m>>q>>s&&n!=0) {
    vector<tuple<int,int,int>> edges;
    vector<vector<pair<int,int>>> adjList(n,vector<pair<int,int>>());
    for(int i=0;i<m;i++) {
      int a,b,c;
      cin>>a>>b>>c;
      adjList[a].push_back({b,c});
      edges.push_back({a,b,c});
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

  // find all nodes part of negative cycle
  vector<bool> neg(n,false);
  for(auto &[x,y,z]:edges){
    if(dist[x]!=numeric_limits<int>::max()&&dist[x]+z<dist[y]) {
      neg[y]=true;
    }
  }
  queue<int> bfs;
  for(int i=0;i<n;i++) {
    if(neg[i]) bfs.push(i);
  }
  while(!bfs.empty()) {
    int top=bfs.front();
    bfs.pop();
    for(auto& [v,w]:adjList[top]) {
      if(!neg[v]) {
        neg[v]=true;
        bfs.push(v);
      }
    }
  }
  while(q--) {
    int x;
    cin>>x;
    if(neg[x]) cout<<"-Infinity";
    else if (dist[x]==numeric_limits<int>::max()) cout<<"Impossible";
    else cout<<dist[x];
    cout<<"\n";
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
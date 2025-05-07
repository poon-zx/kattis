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

bool isBipartite(int V, const vector<vector<int>>& adj) {
    vector<int> color(V, -1);
    queue<int> q;

    for (int src = 0; src < V; ++src) {
        if (color[src] != -1) continue;

        color[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int u = q.front(); 
            q.pop();
            for (int v : adj[u]) {
                if (color[v] == -1) {
                    // Assign opposite color to neighbour
                    color[v] = color[u] ^ 1;
                    q.push(v);
                }
                else if (color[v] == color[u]) {
                    // Found same‐color neighbor → not bipartite
                    return false;
                }
            }
        }
    }
    return true;
}

void dfs(int u, unordered_set<int> &visited,vector<vector<int>> &adj) {                                                            
  visited.insert(u);
  for (auto &v: adj[u])                     
    if (visited.find(v)==visited.end()) dfs(v,visited,adj);                                    
}

void solve() {
  int n,m;
  cin>>n>>m;
  vector<vector<int>> adj(n,vector<int>());
  while(m--) {
    int a,b;
    cin>>a>>b;
    adj[a-1].push_back(b-1);
    adj[b-1].push_back(a-1);
  }
  int cc=0;
  unordered_set<int> visited;
  for(int i=0;i<n;i++) {
    if(visited.find(i)==visited.end()) {
      cc++;
      dfs(i,visited,adj);
    }
  }
  if(isBipartite(n,adj)) cout<<cc;
  else cout<<cc-1;

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
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
  int n,m,x,y;
  cin>>n>>m>>x>>y;
  vector<vector<vector<int>>> adjList(n+1);
  for (int i=0;i<m;i++) {
    int a,b,w,c;
    cin>>a>>b>>w>>c;
    adjList[a].push_back({b,w,c});
    adjList[b].push_back({a,w,c});
  }
  vector<vector<ll>> dist(n+1,vector<ll>(3,numeric_limits<ll>::max()));
  priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> q;
  q.push({0,0,0,x});
  while (!q.empty()) {
    vector<ll> front=q.top();
    q.pop();
    for (auto neigh:adjList[front[3]]) {
      int shaman=(neigh[2]==1)?1:0;
      int titan=(neigh[2]==2)?1:0;
      if ((dist[neigh[0]][0]>front[0]+titan)||
        (dist[neigh[0]][0]==front[0]+titan&&dist[neigh[0]][1]>front[1]+shaman)||
        (dist[neigh[0]][0]==front[0]+titan&&dist[neigh[0]][1]==front[1]+shaman&&dist[neigh[0]][2]>front[2]+neigh[1])) {
          dist[neigh[0]]={front[0]+titan,front[1]+shaman,front[2]+neigh[1]};
          q.push({front[0]+titan,front[1]+shaman,front[2]+neigh[1],neigh[0]});
        }
    }
  }
  if (dist[y][0]==numeric_limits<ll>::max()) {cout<<"IMPOSSIBLE";}
  else {cout<<dist[y][2]<<" "<<dist[y][1]<<" "<<dist[y][0];}
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
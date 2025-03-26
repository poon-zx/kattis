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
  int n,m,a,b,k,g;
  cin>>n>>m>>a>>b>>k>>g;
  vector<int> george(g);
  for (int i=0;i<g;i++) cin>>george[i];
  vector<vector<pair<int,int>>> adjList(n+1,vector<pair<int,int>>());
  for (int i=0;i<m;i++) {
    int x,y,z;
    cin>>x>>y>>z;
    adjList[x].push_back({y,z});
    adjList[y].push_back({x,z});
  }
  vector<int> george_times(g);
  int curr=0;
  map<pair<int,int>,pair<int,int>> blocked;
  for (int i=0;i<g-1;i++) {
    int time;
    for (auto& nei:adjList[george[i]]) {
      if (nei.first==george[i+1]) time=nei.second;
    }
    blocked[{min(george[i],george[i+1]),max(george[i],george[i+1])}]={curr,curr+time-1};
    curr+=time;
  }
  vector<int> dist(n+1,numeric_limits<int>::max());
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  pq.push({k,a});
  while (!pq.empty()) {
    pair<int,int> top=pq.top();
    pq.pop();
    if (top.first>dist[top.second]) continue;
    for (auto& nei:adjList[top.second]) {
      pair<int,int> curr_b=blocked[{min(nei.first,top.second),max(nei.first,top.second)}];
      if (curr_b.second>=top.first&&curr_b.first<=top.first) {
        if (curr_b.second+1+nei.second<dist[nei.first]) {
          dist[nei.first]=curr_b.second+1+nei.second;
          pq.push({dist[nei.first],nei.first});
        }
      } else {
        if (top.first+nei.second<dist[nei.first]) {
          dist[nei.first]=top.first+nei.second;
          pq.push({dist[nei.first],nei.first});
        }
      }
    }
  }
  cout<<dist[b]-k;
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
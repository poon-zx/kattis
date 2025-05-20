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
  int p,t;
  cin>>p>>t;
  vector<vector<pair<int,int>>> adjList(p,vector<pair<int,int>>());
  vector<vector<int>> edges;
  for(int i=0;i<t;i++) {
    int a,b,c;
    cin>>a>>b>>c;
    adjList[a].push_back({b,c});
    adjList[b].push_back({a,c});
    edges.push_back({a,b,c});
  }
  vector<int> dist(p,numeric_limits<int>::max());
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  pq.push({0,0});
  dist[0]=0;
  while(!pq.empty()) {
    pair<int,int> top=pq.top();
    pq.pop();
    for (auto& [x,y]:adjList[top.second]) {
      if(dist[x]>dist[top.second]+y) {
        dist[x]=dist[top.second]+y;
        pq.push({dist[x],x});
      }
    }
  }
  vector<int> dist1(p,numeric_limits<int>::max());
  pq=priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>();
  pq.push({0,p-1});
  dist1[p-1]=0;
  while(!pq.empty()) {
    pair<int,int> top=pq.top();
    pq.pop();
    for (auto& [x,y]:adjList[top.second]) {
      if(dist1[x]>dist1[top.second]+y) {
        dist1[x]=dist1[top.second]+y;
        pq.push({dist1[x],x});
      }
    }
  }
  ll res=0;
  int shortest=dist[p-1];
  for(auto& v:edges) {
    if(dist[v[0]]+v[2]+dist1[v[1]]==shortest||dist[v[1]]+v[2]+dist1[v[0]]==shortest) {
      res+=(ll)v[2];
    }
  }
  cout<<2*res;
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
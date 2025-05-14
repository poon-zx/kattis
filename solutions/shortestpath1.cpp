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
    vector<vector<pair<int,int>>> adjList(n,vector<pair<int,int>>());
    for(int i=0;i<m;i++) {
      int a,b,c;
      cin>>a>>b>>c;
      adjList[a].push_back({b,c});
    }
    vector<int> dist(n,numeric_limits<int>::max());
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,s});
    dist[s]=0;
    while(!pq.empty()) {
      pair<int,int> top=pq.top();
      pq.pop();
      for(auto &[x,y]:adjList[top.second]) {
        if(dist[x]>dist[top.second]+y) {
          dist[x]=dist[top.second]+y;
          pq.push({dist[top.second]+y,x});
        }
      }
    }
    for(int i=0;i<q;i++) {
      int qu;
      cin>>qu;
      if(dist[qu]!=numeric_limits<int>::max()) cout<<dist[qu]<<"\n";
      else cout<<"Impossible"<<"\n";
    }
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
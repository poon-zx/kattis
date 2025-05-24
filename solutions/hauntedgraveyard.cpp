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
  int w,h;
  while(cin>>w>>h&&w!=0) {
    int g;
    cin>>g;
    unordered_set<int> grave;
    unordered_set<int> holes;
    for(int i=0;i<g;i++) {
      int a,b;
      cin>>a>>b;
      grave.insert(a*h+b);
    }
    vector<tuple<int,int,int>> edges;
    int e;
    cin>>e;
    for(int i=0;i<e;i++) {
      int x1,y1,x2,y2,t;
      cin>>x1>>y1>>x2>>y2>>t;
      edges.push_back({x1*h+y1,x2*h+y2,t});
      holes.insert(x1*h+y1);
    }
    int exit=(w-1)*h+h-1;
    for(int i=0;i<w;i++) {
      for(int j=0;j<h;j++) {
        int curr=i*h+j;
        if(curr==exit||grave.find(curr)!=grave.end()||holes.find(curr)!=holes.end()) continue;
        if(i>0&&grave.find(curr-h)==grave.end()) edges.push_back({curr,curr-h,1});
        if(i<w-1&&grave.find(curr+h)==grave.end()) edges.push_back({curr,curr+h,1});
        if(j>0&&grave.find(curr-1)==grave.end()) edges.push_back({curr,curr-1,1});
        if(j<h-1&&grave.find(curr+1)==grave.end()) edges.push_back({curr,curr+1,1});
      }
    }
    int n=(w-1)*h+h-1;
    vector<int> dist(n+1,numeric_limits<int>::max());
    dist[0]=0;
    for(int i=0;i<n;i++) {
      bool modified=false;
      for (auto& [u,v,w] : edges) {
        if (dist[u] != numeric_limits<int>::max() && dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          modified = true;
        }
      }
      if (!modified) break;
    }
    bool negative=false;
    for(auto &[x,y,z]:edges){
      if(dist[x]!=numeric_limits<int>::max()&&dist[x]+z<dist[y]) {
        negative=true;
        break;
      }
    }
    if(negative) cout<<"Never"<<"\n";
    else if (dist[n]==numeric_limits<int>::max()) cout<<"Impossible"<<"\n";
    else cout<<dist[n]<<"\n";
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
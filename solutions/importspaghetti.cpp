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
const ll INF = (ll)1e15;

constexpr array<array<int, 2>, 4> directions{{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}};

// vector<vector<int>> v(3, vector<int>(4,0) 3x4 filled with 0s

void solve() {
  int n;
  cin>>n;
  unordered_map<string,int> ind;
  vector<string> files(n);
  for(int i=0;i<n;i++) {
    cin>>files[i];
    ind[files[i]]=i;
  }
  vector<vector<ll>> dist(n,vector<ll>(n,INF));
  vector<vector<int>> nxt(n,vector<int>(n,-1));
  vector<vector<int>> adj(n,vector<int>(n,false));
  for(int i=0;i<n;i++) {
    string s;
    int a;
    cin>>s>>a;
    int curr=ind[s];
    for(int i=0;i<a;i++) {
      string import,clas;
      cin>>import>>clas;
      while(clas.back()==',') {
        clas=clas.substr(0,clas.size()-1);
        int num=ind[clas];
        dist[curr][num]=1;
        adj[curr][num]=true;
        nxt[curr][num]=num;
        cin>>clas;
      }
      int num=ind[clas];
      dist[curr][num]=1;
      adj[curr][num]=true;
      nxt[curr][num]=num;
    }
  }
  for(int i=0;i<n;i++) {
    dist[i][i]=0;
    nxt[i][i]=i;
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      if (dist[i][k] == INF) continue;
      for (int j = 0; j < n; ++j) {
        if (dist[k][j] == INF) continue;
        ll alt=dist[i][k] + dist[k][j];
        if(alt<dist[i][j]) {
          dist[i][j]=alt;
          nxt[i][j]=nxt[i][k];
        }
      }
    }
  }

  ll best=INF;
  int bu=-1,bv=-1;
  for(int u=0;u<n;u++) {
    for(int v=0;v<n;v++) {
      if(!adj[u][v]) continue;
      if(dist[v][u]==INF) continue; // no way back
      ll cycleLen=1+dist[v][u];
      if(cycleLen<best) {
        best=cycleLen;
        bu=u;
        bv=v;
      }
    }
  }
  if(best==INF) {cout<<"SHIP IT\n";return;}

  vector<int> path={bv};
  while(path.back()!=bu) {
    path.push_back(nxt[path.back()][bu]);
  }
  cout<<files[bu];
  for(int i=0;i<(int)path.size()-1;i++) {
    cout<<' '<<files[path[i]];
  }
  cout<<"\n";
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
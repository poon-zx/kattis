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
  int n,m,q;
  while(cin>>n>>m>>q&&n!=0) {
    vector<vector<ll>> dist(n,vector<ll>(n,INF));
    for (int i = 0; i < n; ++i) dist[i][i] = 0;
    for(int i=0;i<m;i++) {
      int u,v,w;
      cin>>u>>v>>w;
      dist[u][v]=min((ll)w,dist[u][v]);
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (dist[i][k] == INF) continue;
            for (int j = 0; j < n; ++j) {
                if (dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    vector<vector<bool>> neg(n, vector<bool>(n, false));
    for (int k = 0; k < n; k++) {
        if (dist[k][k] < 0) {
            for (int i = 0; i < n; i++) {
                if (dist[i][k] == INF) continue;
                for (int j = 0; j < n; j++) {
                    if (dist[k][j] == INF) continue;
                    neg[i][j] = true;
                }
            }
        }
    }

    for(int i=0;i<q;i++) {
      int a,b;
      cin>>a>>b;
      if(neg[a][b]) cout<<"-Infinity"<<"\n";
      else if(dist[a][b]==INF) cout<<"Impossible"<<"\n";
      else cout<<dist[a][b]<<"\n";
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
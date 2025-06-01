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
void solve(){
    int N,T;
    cin>>N>>T;
    vector<pair<ll,ll>> cheers(N+2);
    cheers[1]={1,1};
    for(int i=2;i<=N+1;i++){
      cin>>cheers[i].first>>cheers[i].second;
    }

    // 2) Determine how far below 0 / above T we might need to go
    int maxPos=0,maxNeg=0;
    for(int i=1;i<=N+1;i++){
      ll s=cheers[i].first;
      if(s>0) maxPos=max(maxPos,(int)s);
      else maxNeg=max(maxNeg,(int)-s);
    }
    int lo=-maxNeg, hi=T+maxPos;
    int M=hi-lo+1;
    auto idx=[&](int x){return x-lo;};

    // 3) Set up bucketed Dijkstra (Dial's algorithm)
    const int INF=T+1;
    vector<int> dist(M, INF),prev_node(M, -1),prev_cheer(M, -1);
    vector<vector<int>> buckets(T+1);

    dist[idx(0)]=0;
    buckets[0].push_back(idx(0));

    // 4) Relax in increasing order of distance d = 0..T
    bool reached=false;
    for(int d=0;d<=T&&!reached; d++){
      for(int u_i:buckets[d]){
        if (dist[u_i]!=d) continue;
        int u = u_i+lo;
        if (u==T) {                
          reached = true;
          break;
        }
        // relax all cheers
        for(int i=1;i<= N+1;i++){
          int v=u+(int)cheers[i].first;
          if (v<lo||v>hi) continue;
          int v_i=idx(v);
          int nd=d+(int)cheers[i].second;
          if (nd<dist[v_i]){
            dist[v_i]=nd;
            prev_node[v_i]  = u_i;
            prev_cheer[v_i] = i;
            if (nd <= T)
              buckets[nd].push_back(v_i);
          }
        }
      }
    }

    // 5) Reconstruct the path from T back to 0
    vector<int> seq;
    for(int cur=idx(T); cur != idx(0); cur = prev_node[cur]){
      seq.push_back(prev_cheer[cur]);
    }
    reverse(seq.begin(), seq.end());

    // 6) Output
    cout << seq.size() << "\n";
    for(int c : seq) cout << c << " ";
    cout << "\n";
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
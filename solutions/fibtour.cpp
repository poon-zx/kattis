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
  int n,m;
  cin>>n>>m;
  vector<ll> mansions(n);
  for(int i=0;i<n;i++) cin>>mansions[i];
  vector<vector<int>> adj(n);
  for (int i=0;i<m;i++) {
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<ll> fib={0,1,1};
  while(true) {
    auto nxt=fib[fib.size()-1]+fib[fib.size()-2];
    if(nxt>1000000000000000000LL) break;
    fib.push_back(nxt);
  }
  int F=fib.size()-1;
  unordered_map<ll,vector<int>> fibIdx;
  fibIdx.reserve(F*2);
  for(int i=1;i<=F;i++) fibIdx[fib[i]].push_back(i);
  vector<vector<int>> mapping(n);
  vector<vector<int>> nodesAt(F+2);
  for(int u=0;u<n;u++) {
    auto it=fibIdx.find(mansions[u]);
    if(it!=fibIdx.end()) {
      mapping[u]=it->second;
      for(int idx:mapping[u]) nodesAt[idx].push_back(u);
    }
  }
  // dp[u][k] = longest fib-path ending at node u with fib-index = mapping[u][k]
  vector<vector<int>> dp(n);
  for(int u=0;u<n;u++) {
    if(!mapping[u].empty()) dp[u].assign(mapping[u].size(),1);
  }
  int ans=0;
  for(int u=0;u<n;u++) {
    for(int v:dp[u]) ans=max(ans,v);
  }
  for(int i=1;i<=F;i++) {
    for(int u:nodesAt[i]) {
      auto &mu=mapping[u];
      int pu=(mu.size() == 1 ? 0 : (mu[0] == i ? 0 : 1));
      int cur=dp[u][pu];
      for(int v:adj[u]) {
        auto &mv=mapping[v];
        for(int q=0;q<(int)mv.size();q++) {
          if(mv[q]==i+1) {
            int cand=cur+1;
            if(dp[v][q]<cand) {
              dp[v][q]=cand;
              ans=max(ans,cand);
            }
          }
        }
      }
    }
  }
  cout<<ans;
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
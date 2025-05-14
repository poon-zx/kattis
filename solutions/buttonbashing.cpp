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
  int n,t;
  cin>>n>>t;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  vector<int> dist(3601,numeric_limits<int>::max());
  deque<int> q;
  q.push_back(0);
  dist[0]=0;
  while(!q.empty()) {
    int curr=q.front();
    q.pop_front();
    for (auto &num:v) {
      int ne=curr+num;
      ne=min(max(ne,0),3600);
      if(dist[ne]>dist[curr]+1) {
        dist[ne]=dist[curr]+1;
        q.push_back(ne);
      }
    }
  }
  if(dist[t]!=numeric_limits<int>::max()) cout<<dist[t]<<" "<<0<<"\n";
  else {
    for(int i=t+1;i<dist.size();i++) {
      if(dist[i]!=numeric_limits<int>::max()) {
        cout<<dist[i]<<" "<<i-t<<"\n";
        return;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tc;
  cin>>tc;
  while (tc--) {
    solve();
  }

  return 0;
}
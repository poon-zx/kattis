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
  vector<vector<int>> adjList(n+1,vector<int>());
  for (int i=0;i<m;i++) {
    int a,b;
    cin>>a>>b;
    adjList[a].push_back(b);
    adjList[b].push_back(a);
  }
  vector<int> size(n+1);
  for (int i=1;i<=n;i++) {
    int c;
    cin>>c;
    size[i]=c;
  }
  priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
  pq.push({0,1});
  ll res=size[1];
  unordered_set<int> visited;
  while (!pq.empty()) {
    if (res<=pq.top().first) break;
    //cout<<pq.top().first<<" "<<pq.top().second<<" ";
    pair<ll,int> top=pq.top();
    pq.pop();
    if (visited.find(top.second)!=visited.end()) continue;
    visited.insert(top.second);
    res+=top.first;
    for (auto nei:adjList[top.second]) {
      if (visited.find(nei)==visited.end()) {
        pq.push({size[nei],nei});
      }
    }
  }
  cout<<res;
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
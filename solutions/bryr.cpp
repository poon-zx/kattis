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
  vector<vector<pair<int,int>>> adjList(n+1);
  for (int i=0;i<m;i++) {
    int a,b,c;
    cin>>a>>b>>c;
    adjList[a].push_back({b,c});
    adjList[b].push_back({a,c});
  }
  deque<int> q;
  q.push_back(1);
  vector<ll> dist(n+1,numeric_limits<ll>::max());
  dist[1]=0;
  while (!q.empty()) {
    int front=q.front();
    q.pop_front();
    if (front==n) {
      cout<<dist[n];
      return;
    }
    for (auto item:adjList[front]) {
      if (dist[item.first]>dist[front]+item.second) {
        dist[item.first]=dist[front]+item.second;
      
        if (item.second==1) {
            q.push_back(item.first);
        } else {
            q.push_front(item.first);
        }
      }
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
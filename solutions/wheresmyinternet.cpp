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
  set<int> visited;
  queue<int> q;
  q.push(1);
  visited.insert(1);
  while (!q.empty()) {
    int first=q.front();
    q.pop();
    for (auto& num:adjList[first]) {
      if (visited.find(num)==visited.end()) {
        visited.insert(num);
        q.push(num);
      }
    }
  }
  if (visited.size()==n) {
    cout<<"Connected";
    return;
  }
  for (int i=1;i<=n;i++) {
    if (visited.find(i)==visited.end()) cout<<i<<"\n";
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
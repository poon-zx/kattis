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
  vector<vector<int>> adjList(n,vector<int>());
  for (int i=0;i<m;i++) {
    int a,b;
    cin>>a>>b;
    adjList[a].push_back(b);
    adjList[b].push_back(a);
  }
  set<int> visited;
  int res=0;
  for (int i=0;i<n;i++) {
    if (visited.find(i)==visited.end()) {
        queue<int> q;
        q.push(i);
        visited.insert(i);
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
        res++;
    }
  }
  cout<<res-1<<"\n";
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
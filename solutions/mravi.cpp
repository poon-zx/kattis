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

vector<vector<vector<int>>> adjList;
vector<double> required;

double dfs(int node) {
  if (adjList[node].empty()) {
    return required[node];
  }
  vector<vector<int>> neighbors=adjList[node];
  double res=0;
  for (auto neigh:neighbors) {
    int node=neigh[0];
    int percent=neigh[1];
    int super=neigh[2];
    double child=dfs(node);
    double req;
    if (super==1) {
      req=sqrt(child)*100/percent;
    } else {
      req=child*100/percent;
    }
    res=max(res,req);
  }
  return res;
}


void solve() {
  int n;
  cin>>n;
  adjList.resize(n+1);
  required.resize(n+1);
  for (int i=0;i<n-1;i++) {
    int a,b,x,t;
    cin>>a>>b>>x>>t;
    adjList[a].push_back({b,x,t});
  }
  for (int i=1;i<=n;i++) {
    cin>>required[i];
  }
  double res=dfs(1);
  cout<<fixed<<setprecision(3)<<res;
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
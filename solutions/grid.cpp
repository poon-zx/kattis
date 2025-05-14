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
  vector<vector<int>> v(n,vector<int>(m));
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      char c;
      cin>>c;
      v[i][j]=c-'0';
    }
  }
  vector<vector<int>> dist(n,vector<int>(m,numeric_limits<int>::max()));
  deque<pair<int,int>> q;
  q.push_back({0,0});
  dist[0][0]=0;
  while(!q.empty()) {
    pair<int,int> top=q.front();
    q.pop_front();
    int num=v[top.first][top.second];
    vector<pair<int,int>> dirs={{num,0},{-num,0},{0,num},{0,-num}};
    for(auto &[x,y]:dirs) {
      int new_x=x+top.first,new_y=y+top.second;
      if(new_x<0||new_x>=n||new_y<0||new_y>=m) continue;
      if(dist[new_x][new_y]>dist[top.first][top.second]+1) {
        dist[new_x][new_y]=dist[top.first][top.second]+1;
        q.push_back({new_x,new_y});
      }
    }
  }
  if(dist[n-1][m-1]!=numeric_limits<int>::max()) cout<<dist[n-1][m-1];
  else cout<<-1;
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
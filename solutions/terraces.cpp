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

set<pair<int,int>> sett;

ll traverse(const vector<vector<int>>& v,int i,int j) {
  queue<pair<int,int>> q;
  q.push({i,j});
  sett.insert({i,j});
  int curr=v[i][j];
  ll res=1;
  bool lower=false;
  while (!q.empty()) {
    pair<int,int> p=q.front();
    q.pop();
    int f=p.first;
    int s=p.second;
    for (auto& [x,y]:directions) {
      if (f+x>=0&&f+x<v.size()&&s+y>=0&&s+y<v[0].size()) {
        if (v[f+x][s+y]==curr&&sett.find({f+x,s+y})==sett.end()) {
          sett.insert({f+x,s+y});
          res++;
          q.push({f+x,s+y});
        } else if (v[f+x][s+y]<curr) {
          lower=true;
        }
      }
    }
  }
  if (!lower) return res;
  else return 0;
}

void solve() {
  int x,y;
  cin>>x>>y;
  vector<vector<int>> v(y,vector<int>(x,0));
  for (int i=0;i<y;i++) {
    for (int j=0;j<x;j++) cin>>v[i][j];
  }
  ll res=0;
  for (int i=0;i<y;i++) {
    for (int j=0;j<x;j++) {
      if (sett.find({i,j})==sett.end()) {
        res += traverse(v,i,j);
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
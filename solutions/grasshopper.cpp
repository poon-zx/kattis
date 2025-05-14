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

constexpr array<array<int, 2>, 8> directions{{
    {-2, -1},
    {-2, 1},
    {2, -1},
    {2, 1},
    {1, -2},
    {-1, -2},
    {1, 2},
    {-1, 2},
}};

// vector<vector<int>> v(3, vector<int>(4,0) 3x4 filled with 0s

void solve() {
  int r,c,gr,gc,lr,lc;
  while(cin>>r>>c>>gr>>gc>>lr>>lc) {
    deque<pair<int,int>> q;
    q.push_back({gr,gc});
    int res=0;
    vector<vector<bool>> visited(r+1,vector<bool>(c+1,false));
    visited[gr][gc]=true;
    while(!q.empty()) {
      bool found=false;
      int size=q.size();
      while(size--) {
        pair<int,int> top=q.front();
        q.pop_front();
        if(top.first==lr&&top.second==lc) {
          cout<<res<<endl;
          found=true;
          break;
        }
        for(auto &[x,y]:directions) {
          int new_x=x+top.first;
          int new_y=y+top.second;
          if(new_x<1||new_x>r||new_y<1||new_y>c||visited[new_x][new_y]) continue;
          q.push_back({new_x,new_y});
          visited[new_x][new_y]=true;
        }
      }
      if(found) break;
      res++;
    }
    if(!visited[lr][lc]) cout<<"impossible"<<endl;
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
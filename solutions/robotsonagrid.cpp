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

constexpr ll MOD = (1LL<<31)-1;

constexpr array<array<int, 2>, 4> directions{{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}};

// vector<vector<int>> v(3, vector<int>(4,0) 3x4 filled with 0s

void solve() {
  int n;
  cin>>n;
  vector<ll> dp(n,0);
  dp[0]=1LL;
  vector<string> grid(n);
  for(int i=0;i<n;i++) {
    string s;
    cin>>s;
    grid[i]=s;
    if(i==0) {
      for (int i=1;i<n;i++) {
        if(s[i]=='#') dp[i]=0;
        else dp[i]=dp[i-1];
      }
    }
    else {
      vector<ll> new_dp(n,0);
      for(int i=0;i<n;i++) {
        if(s[i]=='#') continue;
        if(i!=0) new_dp[i]=(new_dp[i]+new_dp[i-1])%MOD;
        new_dp[i]+=dp[i];
        new_dp[i]%=MOD;
      }
      dp=new_dp;
    }
  }
  if(dp[n-1]!=0) {cout<<dp[n-1];return;}
  // bfs to find path
  deque<pair<int,int>> q;
  q.push_back({0,0});
  grid[0][0]='#';
  bool found=false;
  while(!q.empty()) {
    pair<int,int> top=q.front(); 
    q.pop_front();
    if(top.first==n-1&&top.second==n-1) {found=true;break;}
    for(auto &[x,y]:directions) {
      int new_x=top.first+x;
      int new_y=top.second+y;
      if(new_x>=0&&new_x<n&&new_y>=0&&new_y<n&&grid[new_x][new_y]!='#') {
        q.push_back({new_x,new_y});
        grid[new_x][new_y]='#';
      }
    }
  }
  if(found) cout<<"THE GAME IS A LIE";
  else cout<<"INCONCEIVABLE";
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
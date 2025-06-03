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

static ll dp[2][51][51][51][51];

ll dfs(int leg,int l2,int r2,int l1,int r1) {
  if(l2==0&&r2==0&&l1==0&&r1==0) return 1;
  ll &res=dp[leg][l2][r2][l1][r1];
  if(res>=0) return res;
  res=0;
  if(leg==0) {
    if(l2>0) res+=dfs(1,l2-1,r2,l1,r1);
    if(l1>0) res+=dfs(1,l2,r2,l1-1,r1);
  } else {
    if(r2>0) res+=dfs(0,l2,r2-1,l1,r1);
    if(r1>0) res+=dfs(0,l2,r2,l1,r1-1);
  }
  return res;
}

void solve() {
  int n;
  cin>>n;
  for(int t=1;t<=n;t++) {
    cout<<t<<" ";
    int a,s;
    cin>>a>>s;
    int m=s/2;
    int startX=(m+2)/3;
    int endX=m/2;
    ll ans=0;
    for (int x=startX;x<=endX;x++) {
      int y=m-2*x;
      for(int leg=0;leg<2;leg++) {
        for(int l2=0;l2<=x;l2++) {
          for(int r2=0;r2<=x;r2++) {
            for(int l1=0;l1<=y;l1++) {
              for(int r1=0;r1<=y;r1++) {
                dp[leg][l2][r2][l1][r1]=-1;
              }
            }
          }
        }
      }
      ans+=dfs(0,x,x,y,y);
    }
    cout<<ans<<endl;
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
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
  int n;
  cin>>n;
  vector<int> a(101);
  vector<int> b(101);
  int max_a=0,max_b=0,min_a=101,min_b=101;
  for (int i=0;i<n;i++) {
    int x,y;
    cin>>x>>y;
    max_b=max(max_b,y);
    min_a=min(min_a,x);
    a[x]++;
    b[y]++;
    int total=i+1;
    int curr=0;
    int res=0;
    int a_pt=min_a;
    int b_pt=max_b;
    int a_curr=a[a_pt];
    int b_curr=b[b_pt];
    while(curr<total) {
      res=max(a_pt+b_pt,res);
      int take=min(a_curr,b_curr);
      curr+=take;
      a_curr-=take;
      b_curr-=take;
      if(a_curr==0) {
        a_pt++;
        while(a_pt<100&&a[a_pt]==0) a_pt++;
        a_curr=a[a_pt];
      }
      if(b_curr==0) {
        b_pt--;
        while(b_pt>=0&&b[b_pt]==0) b_pt--;
        b_curr=b[b_pt];
      }
    }
    cout<<res<<"\n";
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
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
  int t;
  cin>>t;
  for (int i=1;i<=t;i++) {
    int n;
    cin>>n;
    vector<int> v(n);
    for (int j=0;j<n;j++) {
      cin>>v[j];
    }
    unordered_map<int,int> map;
    int total=1<<n;
    bool found=false;
    int mask1,mask2;
    for (int mask=1;mask<total&&!found;mask++) {
      int curr=0;
      for (int j=0;j<n;j++) {
        if (mask&(1<<j)) {
          curr+=v[j];
        }
      }
      if (map.find(curr)!=map.end()) {
        found=true;
        mask1=map[curr];
        mask2=mask;
      } else map[curr]=mask;
    }
    cout<<"Case #"<<i<<":\n";
    if (found) {
      for (int j=0;j<n;j++) {
        if (mask1&(1<<j)) cout<<v[j]<<" ";
      }
      cout<<"\n";
      for (int j=0;j<n;j++) {
        if (mask2&(1<<j)) cout<<v[j]<<" ";
      }
      cout<<"\n";
    } else cout<<"Impossible\n";
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
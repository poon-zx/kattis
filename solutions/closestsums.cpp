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
  int i=1;
  while(cin>>n) {
    vector<ll> v(n);
    for (int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    int m;
    cin>>m;
    cout<<"Case "<<i<<":\n";
    for (int j=0;j<m;j++) {
      ll curr;
      cin>>curr;
      int l=0,r=n-1;
      int close=MOD;
      while (l<r) {
        ll sum=v[l]+v[r];
        if(abs(sum-curr)<abs(close-curr)) close=sum;
        if(sum>curr) r--;
        else if (sum<curr) l++;
        else break;
      }
      cout<<"Closest sum to "<<curr<<" is "<<close<<".\n";
    }
    i++;
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
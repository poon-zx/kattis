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
  for (int i=1;i<=n;i++) {
    int t;
    char c;
    unsigned int a,b;
    cin>>t>>a>>c>>b;
    vector<int> bits;
    while (a!=1||b!=1) {
      if (a<b) {
        bits.push_back(0);
        b=b-a;
      } else {
        bits.push_back(1);
        a=a-b;
      }
    }
    reverse(bits.begin(),bits.end());
    unsigned int res=1;
    for (int bit:bits) {
      res=2*res+bit;
    }
    cout<<i<<" "<<res<<"\n";
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
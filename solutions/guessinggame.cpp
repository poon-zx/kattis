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
  string s;
  int l=0,r=10;
  bool lying=false;
  while (cin>>n&&n!=0) {
    cin.ignore();
    getline(cin,s);
    if (s=="too low") {
      if (r<=n) lying=true;
      else l=max(l,n+1);
    } else if (s=="too high") {
      if (l>=n) lying=true;
      else r=min(r,n-1);
    } else {
      if (n<l||n>r) lying=true;
      if (lying) cout<<"Stan is dishonest"<<"\n";
      else cout<<"Stan may be honest"<<"\n";
      lying=false;
      l=0,r=10;
    }
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
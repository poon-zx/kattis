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
  int t,b;
  cin>>t>>b;
  vector<int> shops(b);
  for (int i=0;i<b;i++) cin>>shops[i];
  unordered_map<string,int> map;
  for (int i=0;i<t;i++) {
    string s;
    int a;
    cin>>s>>a;
    if (map.find(s)==map.end()) map[s]=0;
    map[s]=max(map[s],a);
  }
  for (int i=0;i<b;i++) {
    int curr=shops[i];
    int res=0;
    for (int j=0;j<curr;j++) {
      string s;
      int a;
      cin>>s>>a;
      res+=map[s]-a;
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
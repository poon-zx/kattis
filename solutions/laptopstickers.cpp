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
  int l,h,n;
  cin>>l>>h>>n;
  string s(l,'_');
  vector<string> laptop(h,s);
  char curr='a';
  for (int i=0;i<n;i++) {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    for (int j=d;j<min(d+b,h);j++) {
      for (int o=c;o<min(c+a,l);o++) {
        laptop[j][o]=curr;
      }
    }
    curr++;
  }
  for (int i=0;i<laptop.size();i++) {
    cout<<laptop[i]<<"\n";
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
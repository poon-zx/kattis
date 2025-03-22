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
  int g,n;
  cin>>g>>n;
  vector<pair<int,int>> v(n);
  for (int i=0;i<n;i++) {
    int a,b;
    cin>>a>>b;
    v[i]={a,b};
  }
  sort(v.begin(), v.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
    return a.second < b.second;
  });
  int res=0;
  int last=0;
  for (auto &p:v) {
    if (p.first>=last) {
      res++;
      last=p.second;
      if (res>=g) break;
    }
  }
  cout<<((res>=g)?"YES":"NO");
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
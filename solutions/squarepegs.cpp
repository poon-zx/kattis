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
  int n,m,k;
  cin>>n>>m>>k;
  vector<int> plot(n);
  for(int i=0;i<n;i++) {int a;cin>>a;plot[i]=a*a*4;}
  vector<int> house(m+k);
  for(int i=0;i<m;i++) {int a;cin>>a;house[i]=a*a*4;}
  for(int i=m;i<m+k;i++) {
    int a;
    cin>>a;
    house[i]=2*a*a;
  }
  sort(plot.begin(),plot.end());
  sort(house.begin(),house.end());
  int pointer=0;
  int res=0;
  for (int i=0;i<n;i++) {
    if(pointer==m+k) break;
    if(plot[i]>house[pointer]) {res++;pointer++;}
  }
  cout<<res;
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
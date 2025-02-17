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
  vector<vector<int>> v(n);
  for (int i=0;i<n;i++) {
    int a,b;
    cin>>a>>b;
    v[i]={a,b};
  }
  bool yes=true;
  for (int i=0;i<n;i++) {
    int x=v[i][0];
    int y=v[i][1];
    for (int j=i+1;j<n;j++) {
      int a=v[j][0];
      int b=v[j][1];
      if (x==a||y==b||(x-y)==(a-b)||(x+y)==(a+b)) {
        cout<<"INCORRECT";
        return;
      }
    }
  }
  cout<<"CORRECT";
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
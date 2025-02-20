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
  int n,ind;
  cin>>n>>ind;
  vector<int> v;
  int time=0;
  int total=0;
  for (int i=0;i<n;i++) {
    int t;
    cin>>t;
    if (i!=ind) {
      v.push_back(t);
    } else {
      time+=t;
      total+=t;
    }
  }
  if (time>300) {
    cout<<0<<" "<<0;
    return;
  }
  sort(v.begin(),v.end());
  int p=0;
  while (p<v.size()) {
    if (time+v[p]<=300) {
      time+=v[p];
      total+=time;
      p++;
    } else {
      break;
    }
  }
  cout<<1+p<<" "<<total;
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
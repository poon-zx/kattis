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
  int n,k;
  cin>>n>>k;
  vector<pair<int,int>> v(n,pair<int,int>());
  for (int i=0;i<n;i++) {
    cin>>v[i].first>>v[i].second;
  }
  sort(v.begin(),v.end(),
    [](auto &A,auto &B) {return A.second<B.second;});
  priority_queue<ll,vector<ll>,greater<ll>> pq;
  ll cnt=0;
  for (auto &[s,f]:v) {
    if (pq.size()<k) {
      pq.push(f);
      cnt++;
    } else if (pq.top()<s) {
      pq.pop();
      pq.push(f);
      cnt++;
    }
  }
  cout<<cnt;
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

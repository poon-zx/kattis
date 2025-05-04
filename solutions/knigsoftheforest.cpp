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
  int k,n,y;
  cin>>k>>n>>y;
  ll p;
  cin>>p;
  vector<pair<int,ll>> v(n+k-2,pair<int,ll>());
  for (int i=0;i<n+k-2;i++) cin>>v[i].first>>v[i].second;
  sort(v.begin(),v.end());
  priority_queue<int> pq;
  int pointer=0;
  if(y==2011) {
    pq.push(p);
    while(pointer<k-1) {
      pq.push(v[pointer].second);
      pointer++;
    }
  } else {
    while(pointer<k) {
      pq.push(v[pointer].second);
      pointer++;
    }
  }
  if(pq.top()==p) {cout<<y;return;}
  pq.pop();
  for(int i=2012;i<2011+n;i++) {
    if(y==i) {
      pq.push(p);
    } else {
      pq.push(v[pointer].second);
      pointer++;
    }
    if(pq.top()==p) {cout<<i;return;}
    pq.pop();
  }
  cout<<"unknown";
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
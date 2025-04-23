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

vector<ll> top;
vector<ll> bot;

bool can(int num, const vector<ll> v) {
  ll curr=0;
  for (int i=0;i<v.size();i++) {
    if (v[i]<=num) continue;
    else if (curr==0) curr=v[i];
    else if (curr==v[i]) curr=0;
    else if (curr!=v[i]) return false;
  }
  return curr==0;
}

void solve() {
  int n;
  cin>>n;
  top.resize(n);
  bot.resize(n);
  vector<ll> all(n*2+1);
  all.push_back(0);
  for (int i=0;i<n;i++) {
    cin>>top[i];
    all[i+1]=top[i];
  }
  for (int i=0;i<n;i++) {
    cin>>bot[i];
    all[n+i+1]=bot[i];
  }
  sort(all.begin(),all.end());
  all.erase(unique(all.begin(),all.end()),all.end());
  int l=0,r=n;
  ll res=numeric_limits<ll>::max();
  while (l<=r) {
    int mid=l+(r-l)/2;
    if (can(all[mid],top)&&can(all[mid],bot)) {
      res=min(res,all[mid]);
      r=mid-1;
    } else l=mid+1;
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
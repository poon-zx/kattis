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
  vector<pair<ll,int>> attack;
  vector<pair<ll,int>> defense;
  vector<pair<ll,int>> health;
  for (int i=0;i<n;i++) {
    ll a,b,c;
    cin>>a>>b>>c;
    attack.push_back({a,i});
    defense.push_back({b,i});
    health.push_back({c,i});
  }
  sort(attack.begin(),attack.end(),greater<pair<ll,int>>());
  sort(defense.begin(),defense.end(),greater<pair<ll,int>>());
  sort(health.begin(),health.end(),greater<pair<ll,int>>());
  unordered_set<int> set;
  for (int i=0;i<k;i++) {
    set.insert(attack[i].second);
    set.insert(defense[i].second);
    set.insert(health[i].second);
  }
  cout<<set.size();
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
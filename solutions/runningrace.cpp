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
  int l,k,s;
  cin>>l>>k>>s;
  unordered_map<int,int> counter;
  unordered_map<int,ll> timing;
  for (int i=0;i<l;i++) {
    int n;
    string s;
    cin>>n>>s;
    if (counter.find(n)==counter.end()) {counter[n]=0;}
    counter[n]++;
    ll time=stoi(s.substr(0,2))*60+stoi(s.substr(3,2));
    if (timing.find(n)==timing.end()) {timing[n]=0;}
    timing[n]+=time;
  }
  vector<pair<ll,int>> total_times;
  for (auto item:counter) {
    if (item.second==k) {
      total_times.push_back({timing[item.first],item.first});
    }
  }
  sort(total_times.begin(),total_times.end());
  for (auto c:total_times) {
    cout<<c.second<<"\n";
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
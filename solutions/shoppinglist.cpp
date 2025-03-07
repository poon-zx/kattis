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
  int n,m;
  cin>>n>>m;
  unordered_map<string, int> ma;
  for (int i=0;i<m;i++) {
    string s;
    cin>>s;
    ma[s]=1;
  }
  for (int i=0;i<n-1;i++) {
    unordered_set<string> set;
    for (int j=0;j<m;j++) {
      string s;
      cin>>s;
      if (set.find(s)==set.end()) {
        set.insert(s);
        ma[s]+=1;
      }
    }
  }
  vector<string> v;
  for (auto it: ma) {
    if (it.second==n) {
      v.push_back(it.first);
    }
  }
  sort(v.begin(),v.end());
  cout<<v.size()<<"\n";
  for (string st:v) {
    cout<<st<<"\n";
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
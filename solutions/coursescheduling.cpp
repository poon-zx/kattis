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
  unordered_map<string,unordered_set<string>> m;
  for (int i=0;i<n;i++) {
    string f,l,c;
    cin>>f>>l>>c;
    string name=f+l;
    if (m.find(c)==m.end()) {
      unordered_set<string> s;
      m[c]=s;
    }
    m[c].insert(name);
  }
  vector<string> v;
  for (auto& it:m) {
    v.push_back(it.first);
  }
  sort(v.begin(),v.end());
  for (auto &item:v) {
    cout<<item<<" "<<m[item].size()<<"\n";
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
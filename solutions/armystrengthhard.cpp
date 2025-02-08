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

using i64 = long long;

constexpr int MOD = 1'000'000'007;

constexpr array<array<int, 2>, 4> directions{{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}};

// vector<vector<int>> v(3, vector<int>(4,0) 3x4 filled with 0s

void solve() {
  int god,mecha,t;
  cin>>god>>mecha;
  deque<int> g,m;
  for (int i=0;i<god;i++) {
    cin>>t;
    g.push_back(t);
  }
  for (int i=0;i<mecha;i++) {
    cin>>t;
    m.push_back(t);
  }
  sort(g.begin(),g.end());
  sort(m.begin(),m.end());
  while (g.size()>0 && m.size()>0) {
    if (m[0]>g[0]) {
      g.pop_front();
    } else {
      m.pop_front();
    }
  }
  if (g.size()>0) {cout<<"Godzilla\n";}
  else {cout<<"MechaGodzilla\n";}

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tc;
  cin>>tc;
  while (tc--) {
    solve();
  }

  return 0;
}
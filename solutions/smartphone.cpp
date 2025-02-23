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

int comparee(string s1, string s2) {
  int same=0;
  for (int i=0;i<min(s1.size(),s2.size());i++) {
    if (s1[i]==s2[i]) {same++;}
    else {break;}
  }
  return s2.size()-same+s1.size()-same;
}

void solve() {
  string want,curr,sugg1,sugg2,sugg3;
  cin>>want>>curr>>sugg1>>sugg2>>sugg3;
  cout<<min({comparee(curr,want),1+comparee(sugg1,want),1+comparee(sugg2,want),1+comparee(sugg3,want)})<<"\n";
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
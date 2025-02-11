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
  vector<bool> v(26,false);
  string s;
  getline(cin,s);
  for (auto &c:s) {
    c=tolower(c);
    int asci=c-'a';
    if (0<=asci&&asci<=26) {
      v[asci]=true;
    }
  }
  string missing="";
  bool all=true;
  for (int i=0;i<v.size();i++) {
    if (!v[i]) {
      all=false;
      char a='a'+i;
      missing+=a;
    }
  }
  if (all) {cout<<"pangram\n";}
  else {cout<<"missing "<<missing<<"\n";}
  
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tc;
  cin>>tc;
  cin.ignore();
  while (tc--) {
    solve();
  }

  return 0;
}
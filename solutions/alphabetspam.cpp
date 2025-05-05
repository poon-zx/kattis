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
  string s;
  cin>>s;
  int white=0,low=0,upper=0;
  for (char &c:s) {
    if(c=='_') white++;
    else if(c-'a'>=0&&c-'a'<26) low++;
    else if(c-'A'>=0&&c-'A'<26) upper++;
  }
  int sym=s.size()-white-low-upper;
  double siz=(double)s.size();
  cout<<fixed<<setprecision(6)<<(double)white/siz<<"\n";
  cout<<fixed<<setprecision(6)<<(double)low/siz<<"\n";
  cout<<fixed<<setprecision(6)<<(double)upper/siz<<"\n";
  cout<<fixed<<setprecision(6)<<(double)sym/siz;
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
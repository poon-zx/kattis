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
  string a,b;
  cin>>a>>b;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  string c="",d="";
  int i=0;
  while (i<min(a.size(),b.size())) {
    if (a[i]>b[i]) {
      c+=a[i];
    } else if (a[i]<b[i]) {
      d+=b[i];
    } else {
      c+=a[i];
      d+=b[i];
    }
    i++;
  }
  if (a.size()>b.size()) {
    while (i<a.size()){
      c+=a[i];
      i++;
    }
  } else if (b.size()>a.size()) {
    while (i<b.size()){
      d+=b[i];
      i++;
    }
  }
  reverse(c.begin(), c.end());
  reverse(d.begin(), d.end());
  if (c.empty()) {cout<<"YODA\n";}
  else {cout<<stoi(c)<<"\n";}
  if (d.empty()) {cout<<"YODA";}
  else {cout<<stoi(d);}
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
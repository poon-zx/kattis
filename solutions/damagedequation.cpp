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
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  vector<char> v={'*','+','-','/'};
  bool print=false;
  for (char val1:v) {
    ll left;
    if (val1=='*') left=a*b;
    else if (val1=='+') left=a+b;
    else if (val1=='-') left=a-b;
    else if (b!=0) left=a/b;
    else continue;
    for (char val2:v) {
      ll right;
      if (val2=='*') right=c*d;
      else if (val2=='+') right=c+d;
      else if (val2=='-') right=c-d;
      else if (d!=0) right=c/d;
      else continue;
      if (left==right) {
        print=true;
        cout<<a<<" "<<val1<<" "<<b<<" = "<<c<<" "<<val2<<" "<<d<<"\n";
      }
    }
  }
  if (!print) cout<<"problems ahead";
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
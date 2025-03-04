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
  ll n1,n2;
  while (cin>>n1>>n2) {
    if (n1==0&&n2==0) break;
    ll res=0;
    int carry=0;
    while (n1>0&&n2>0) {
      int curr1=n1%10;
      int curr2=n2%10;
      if (curr1+curr2+carry>=10) {
        carry=1;
        res++;
      } else {
        carry=0;
      }
      n1/=10;
      n2/=10;
    }
    while (n1>0) {
      if (n1%10+carry>=10) {
        res++;
        carry=1;
      } else {
        carry=0;
        break;
      }
      n1/=10;
    }
    while (n2>0) {
      if (n2%10+carry>=10) {
        res++;
        carry=1;
      } else {
        carry=0;
        break;
      }
      n2/=10;
    }
    if (res>0) {
      cout<<res<<" carry operation"<<((res>1)?"s.":".")<<"\n";
    } else {
      cout<<"No carry operation."<<"\n";
    }
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
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

bool isPrime(ll num) {
  if (num<2) {return false;}
  if (num<=3) {return true;}
  for (ll i=2;i*i<=num;i++) {
    if (num%i==0) {
      return false;
    }
  }
  return true;
}

void solve() {
  ll num;
  while (cin>>num&&num!=0) {
    bool prime=isPrime(num);
    ll new_num=2*num+1;
    while (!isPrime(new_num)) {
      new_num++;
    }
    if (prime) {
      cout<<new_num<<"\n";
    } else {
      cout<<new_num<<" ("<<num<<" is not prime)"<<"\n";
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
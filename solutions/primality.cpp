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
#include <random>

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

ll mod_mul(ll a, ll b, ll mod) {
    __int128 res = a;
    res *= b;
    res %= mod;
    return (ll)res;
}

ll pow_mod(ll num, ll b, ll n) {
  if (b==0) return 1;
  else if (b==1) return num%n;
  else if (b%2==0) return pow_mod(mod_mul(num,num,n), b/2,n);
  else return mod_mul(num,pow_mod(mod_mul(num, num, n),b/2,n),n);
};

void solve() {
  ll n;
  cin>>n;
  random_device rd;
  mt19937_64 gen(rd());
  uniform_int_distribution<ll> dist(2, n - 2);
  if (n<2||n==4) {
    cout<<"NO";
    return;
  } else if (n<4) {
    cout<<"YES";
    return;
  }
  for (int i=0;i<10000;i++) {
    if (pow_mod(dist(gen),n-1,n)!=1) {
      cout<<"NO";
      return;
    }
  }
  cout<<"YES";
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
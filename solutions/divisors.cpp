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

vector<int> sieve(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    vector<int> factors;
    for(int i=2;i<=n;i++) {
      if(is_prime[i]) factors.push_back(i);
    }
    return factors;
}

void solve() {
  vector<int> primes=sieve(431);
  ll n,k;
  while(cin>>n>>k) {
    // Legendre's formula
    if(k>n-k) k=n-k;
    ll divisors=1;
    for(int p:primes) {
      if(p>n) break;
      ll e=0; // exponent of p in C(n,k)
      for(ll pw=p;pw<=n;pw*=p) {
        e+=n/pw;
        e-=k/pw;
        e-=(n-k)/pw;
      }
      divisors*=(e+1);
    }
    cout<<divisors<<"\n";
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
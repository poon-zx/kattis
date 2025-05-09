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

ll _sieve_size;
bitset<10000000> bs;                             // 10^7 is the rough limit
vector<ll> p;                                           // compact list of primes

void sieve(ll upperbound) {                      // range = [0..upperbound]
  _sieve_size = upperbound+1;                    // to include upperbound
  bs.set();                                      // all 1s
  bs[0] = bs[1] = 0;                             // except index 0+1
  for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
    // cross out multiples of i starting from i*i
    for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
    p.push_back(i);                              // add prime i to the list
  }
}

vector<ll> primeFactors(ll N) {                         // pre-condition, N >= 1
  vector<ll> factors;
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
    while (N%p[i] == 0) {                        // found a prime for N
      N /= p[i];                                 // remove it from N
      factors.push_back(p[i]);
    }
  if (N != 1) factors.push_back(N);              // remaining N is a prime
  return factors;
}

void solve() {
  ll n;
  vector<ll> v;
  ll maxx=0;
  while(cin>>n) {
    v.push_back(n);
    maxx=max(maxx,abs(n));
  }
  sieve((ll)sqrt(maxx)+100LL);
  for(auto& num:v) {
    if(num<0) {cout<<"-1 ";num=-1LL*num;}
    vector<ll> factors=primeFactors(num);
    ll counter=1;
    for(int i=0;i<factors.size()-1;i++) {
      if(factors[i]==factors[i+1]) counter++;
      else {
        if(counter==1) cout<<factors[i]<<" ";
        else cout<<factors[i]<<"^"<<counter<<" ";
        counter=1;
      }
    }
    if(counter==1) cout<<factors.back()<<" ";
    else cout<<factors.back()<<"^"<<counter<<" ";
    cout<<"\n";
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
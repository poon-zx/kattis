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
  if (num<2) {
    return false;
  }
  for (ll i=2;i*i<=num;i++) {
    if (num%i==0) {
      return false;
    }
  }
  return true;
}

vector<ll> getFactors(ll num) {
  vector<ll> factors;
  while (num%2==0) {
    factors.push_back(2);
    num/=2;
  }
  for (ll i=3;i*i<=num;i+=2) {
    while (num%i==0) {
      factors.push_back(i);
      num/=i;
    }
  }
  if (num>1) {
    factors.push_back(num);
  }
  return factors;
}

void solve() {
  ll n;
  while (cin>>n&&n!=4){
    int i=0;
    while (true) {
      i++;
      if (isPrime(n)) {
        cout<<n<<" "<<i<<"\n";
        break;
      }
      vector<ll> factors=getFactors(n);
      ll sum=0;
      for (auto f:factors) {
        sum+=f;
      }
      n=sum;
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
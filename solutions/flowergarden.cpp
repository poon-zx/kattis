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

vector<bool> sieve(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

void solve() {
  int n,d;
  cin>>n>>d;
  vector<bool> primes=sieve(20000);
  vector<pair<int,int>> v(n+1);
  v[0].first=0;
  v[0].second=0;
  for(int i=1;i<=n;i++) cin>>v[i].first>>v[i].second;
  vector<double> dist(n+1);
  dist[0]=0.0;
  int maxx=0;
  for(int i=1;i<=n;i++) {
    dist[i]=dist[i-1];
    dist[i]+=sqrt(pow(v[i].first-v[i-1].first,2)+pow(v[i].second-v[i-1].second,2));
    if(dist[i]<=(double)d&&primes[i]) maxx=i;
  }
  cout<<maxx<<"\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tc;
  cin>>tc;
  while (tc--) {
    solve();
  }

  return 0;
}
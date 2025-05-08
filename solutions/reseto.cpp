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

int sieve(int n, int k){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    int res=0;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i <= n) {
            for (int j = i; j <= n; j += i) {
                if(!is_prime[j]) continue;
                //cout<<j<<" ";
                if(res+1==k) {return j;}
                res++;
                is_prime[j]=false;
            }
        }
    }
    return 0;
}

void solve() {
  int n,k;
  cin>>n>>k;
  cout<<sieve(n,k);
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
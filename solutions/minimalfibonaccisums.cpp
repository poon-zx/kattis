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
  ll n;
  cin>>n;
  vector<ll> fib;
  if (n==1) {
    cout<<1;
    return;
  } else if (n==2) {
    cout<<2;
    return;
  }
  fib.push_back(1);
  fib.push_back(2);
  int p=2;
  ll curr=3;
  while (curr<=n) {
    fib.push_back(curr);
    p++;
    curr=fib[p-1]+fib[p-2];
  }
  vector<ll> ans;
  for (int i=fib.size()-1;i>=0;i--) {
    //cout<<i<<" "<<fib[i]<<" "<<n<<" ";
    if (n-fib[i]<0) continue;
    else {
      n-=fib[i];
      ans.push_back(fib[i]);
    }
  }
  for (int i=ans.size()-1;i>=0;i--) {
    cout<<ans[i]<<" ";
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
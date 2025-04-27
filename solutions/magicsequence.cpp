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

// Stable counting sort used by radixSort, sorting by digit at exp (1,10,100,…)
void countingSort(vector<long long>& a, int shift) {
    int n = a.size();
    const int B=1<<16; // 16-bit base
    vector<long long> output(n);
    vector<int> cnt(B, 0);

    // count occurrences of each digit
    for (auto x : a) {
        int d = (x >> shift) & 0xFFFF;
        cnt[d]++;
    }
    // prefix sums
    for (int i = 1; i < B; i++)
        cnt[i] += cnt[i - 1];

    // build output (in reverse for stability)
    for (int i = n - 1; i >= 0; i--) {
        int d = (a[i] >> shift) & 0xFFFF;
        output[--cnt[d]] = a[i];
    }

    // copy back
    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

// Main radix-sort routine
void radixSort(vector<long long>& a) {
    if (a.empty()) return;
    countingSort(a,0);
    countingSort(a,16);
}

void solve() {
  int n;
  cin>>n;
  ll a,b,c;
  cin>>a>>b>>c;
  ll x,y;
  cin>>x>>y;
  vector<ll> s(n);
  s[0]=a;
  for (int i=1;i<n;i++) {
    s[i]=(s[i-1]*b+a)%c;
  }
  radixSort(s);
  ll res=0;
  for (int i=0;i<n;i++) {
    res=(res*x+s[i])%y;
  }
  cout<<res<<"\n";
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
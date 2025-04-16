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

class FenwickTree {
 public:
  FenwickTree(int n) : n(n), tree(n + 1, 0LL) {}

  FenwickTree(std::vector<ll>& data): FenwickTree(data.size()) {
    for (int i = 1; i <= n; ++i) {
        tree[i] = data[i-1];
        int parent = i + (i & -i);
        if (parent <= n) {
            tree[parent] += tree[i];
        }
    }
  }

  int query(int l, int r) const { return prefix(r) - prefix(l-1); }

  ll update(int i, ll diff) {
    for (; i <= n; i += i & -i) {
      tree[i] += diff;
    }
  }

  ll prefix(int i) const {
    ll sum = 0;
    for (; i > 0; i -= i & -i) {
      sum += tree[i];
    }
    return sum;
  }

  private:
  const int n;
  std::vector<ll> tree;
};

void solve() {
  int n,q;
  cin>>n>>q;
  FenwickTree ft(n);
  for (int i=0;i<q;i++) {
    char c;
    int a,b;
    cin>>c;
    if (c=='+') {
      cin>>a>>b;
      ft.update(a+1,b);
    } else {
      cin>>a;
      cout<<ft.prefix(a)<<"\n";
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
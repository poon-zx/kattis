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
  FenwickTree(int n) : n(n), tree(n + 1, 0) {}

  FenwickTree(std::vector<int>& data): FenwickTree(data.size()) {
    for (int i = 1; i <= n; ++i) {
        tree[i] = data[i-1];
        int parent = i + (i & -i);
        if (parent <= n) {
            tree[parent] += tree[i];
        }
    }
  }


  int query(int l, int r) const { return prefix(r) - prefix(l-1); }

  void update(int i, int diff) {
    for (; i <= n; i += i & -i) {
      tree[i] += diff;
    }
  }

  int prefix(int i) const {
    int sum = 0;
    for (; i > 0; i -= i & -i) {
      sum += tree[i];
    }
    return sum;
  }

 private:
  const int n;
  std::vector<int> tree;
};

void solve() {
  int n,k;
  cin>>n>>k;
  vector<bool> bits(n+1,false);
  FenwickTree ft=FenwickTree(n);
  for (int i=0;i<k;i++) {
    char c;
    cin>>c;
    if (c=='F') {
        int num;
        cin>>num;
        bits[num]=!bits[num];
        if (bits[num]) {ft.update(num,1);}
        else {ft.update(num,-1);}
    } else {
        int first,second;
        cin>>first>>second;
        cout<<ft.query(first,second)<<"\n";
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
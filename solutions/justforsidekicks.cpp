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

  void update(int i, ll diff) {
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
  vector<ll> gems(7);
  for (int i=1;i<=6;i++) cin>>gems[i];
  vector<FenwickTree> fts(7,FenwickTree(n));
  string s;
  cin>>s;
  for (int i=0;i<n;i++) {
    char c=s[i];
    int num=c-'0';
    fts[num].update(i+1,1);
  }
  for (int i=0;i<q;i++) {
    int a;
    cin>>a;
    if (a==1) {
      int b,c;
      cin>>b>>c;
      int curr=s[b-1]-'0';
      s[b-1]=char(c+'0');
      fts[curr].update(b,-1);
      fts[c].update(b,1);
    } else if (a==2) {
      int b;
      ll c;
      cin>>b>>c;
      gems[b]=c;
    } else {
      int b,c;
      cin>>b>>c;
      ll res=0;
      for (int i=1;i<7;i++) {
        res+=fts[i].query(b,c)*gems[i];
      }
      cout<<res<<"\n";
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
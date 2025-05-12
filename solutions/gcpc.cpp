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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;

using ld = long double;

typedef vector<int> pii;
struct cmp {
  bool operator()(pii const &a, pii const&b) const {
    if(a[0]!=b[0]) {
      return a[0]>b[0];
    } else if (a[1]!=b[1]) return a[1]<b[1];
    return a[2]<b[2];
  }
};
typedef tree<pii, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

constexpr int MOD = 1'000'000'007;

constexpr array<array<int, 2>, 4> directions{{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}};

// vector<vector<int>> v(3, vector<int>(4,0) 3x4 filled with 0s

void solve() {
  int n,h;
  cin>>n>>h;
  ordered_set o;
  unordered_map<int,pair<int,int>> m;
  for(int i=0;i<h;i++) {
    int t,p;
    cin>>t>>p;
    if(m.find(t)==m.end()) {
      m[t]={1,p};
      o.insert({1,p,t});
    } else {
      auto it=o.find({m[t].first,m[t].second,t});
      auto key=*it;
      o.erase(it);
      m[t].second+=p;
      m[t].first+=1;
      key[1]+=p;
      key[0]+=1;
      o.insert(key);
    }
    if(m.find(1)==m.end()) {
      cout<<o.size()+1<<"\n";
    } else {
      int it=o.order_of_key({m[1].first,m[1].second,1});
      cout<<it+1<<"\n";
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
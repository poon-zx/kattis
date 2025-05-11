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

// pb_ds order statistics tree
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;

using ld = long double;

constexpr int MOD = 1'000'000'007;

typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

constexpr array<array<int, 2>, 4> directions{{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}};

// vector<vector<int>> v(3, vector<int>(4,0) 3x4 filled with 0s

void solve() {
  int a;
  ordered_set male;
  ordered_set female;
  while(cin>>a&&a!=0) {
    if(a==1) {
      string name;
      int gender;
      cin>>name>>gender;
      if(gender==1) male.insert(name);
      else female.insert(name);
    } else if (a==2) {
      string name;
      cin>>name;
      if(male.find(name)!=male.end()) male.erase(male.find(name));
      else female.erase(female.find(name));
    } else {
      string first,second;
      int gender;
      cin>>first>>second>>gender;
      ll m=(ll)male.order_of_key(second)-(ll)male.order_of_key(first);
      ll f=(ll)female.order_of_key(second)-(ll)female.order_of_key(first);
      if(gender==1) {
        cout<<m<<"\n";
      } else if (gender==2) {
        cout<<f<<"\n";
      } else cout<<m+f<<"\n";
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
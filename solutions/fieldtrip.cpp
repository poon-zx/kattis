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
  int n;
  cin>>n;
  vector<int> v(n);
  for (int i=0;i<n;i++) cin>>v[i];
  vector<int> prefix(n);
  prefix[0]=v[0];
  for (int i=1;i<n;i++) prefix[i]=v[i]+prefix[i-1];
  if (prefix[prefix.size()-1]%3!=0) cout<<-1;
  else {
    int first=-1;
    for (int i=0;i<n;i++) {
      if (prefix[i]==prefix[prefix.size()-1]/3) {
        first=i+1;
      } else if (prefix[i]==prefix[prefix.size()-1]/3*2&&first!=-1) {
        cout<<first<<" "<<i+1;
        return;
      }
    }
    cout<<-1;
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
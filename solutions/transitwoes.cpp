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
  int s,t,n;
  cin>>s>>t>>n;
  vector<int> time(n+1),bus(n),interval(n);
  for(int i=0;i<n+1;i++) cin>>time[i];
  for(int i=0;i<n;i++) cin>>bus[i];
  for(int i=0;i<n;i++) cin>>interval[i];
  int curr=s;
  for(int i=0;i<n;i++) {
    curr+=time[i];
    int times=(curr+interval[i]-1)/interval[i];
    curr=times*interval[i]+bus[i];
  }
  curr+=time[n];
  if(curr<=t) cout<<"yes";
  else cout<<"no";
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
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
  int n,b;
  cin>>n>>b;
  int ind;
  vector<int> v(n);
  vector<int> s(n);
  for(int i=0;i<n;i++) {
    cin>>v[i];
    if(v[i]==b) ind=i;
    s[i]=(v[i]>b?1:v[i]<b?-1:0);
  }
  unordered_map<int,int> cnt;
  cnt[0]=1;
  int curr=0;
  for(int i=ind-1;i>=0;i--) {
    curr+=s[i];
    cnt[curr]++;
  }
  ll res=0;
  curr=0;
  for(int i=ind;i<n;i++) {
    curr+=s[i];
    res+=(ll)cnt[-curr];
  }
  cout<<res;
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
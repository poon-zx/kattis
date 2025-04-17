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
  vector<vector<ll>> v(n,vector<ll>(2,0));
  for (int i=0;i<n;i++) cin>>v[i][0]>>v[i][1];
  sort(v.begin(),v.end(),[](auto &A,auto &B){
    if (A[0]!=B[0]) return A[0]<B[0];
    else return A[1]>B[1];
  });
  vector<int> tails;
  for (int i=0;i<n;i++) {
    int curr=v[i][1];
    auto it=upper_bound(tails.begin(),tails.end(),curr,greater<int>());
    if (it==tails.end()) {
      tails.push_back(curr);
    } else {
      *it=curr;
    }
  }
  cout<<tails.size()<<"\n";
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
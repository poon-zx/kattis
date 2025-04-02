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

vector<ll> nums;
unordered_set<ll> sums;

// vector<vector<int>> v(3, vector<int>(4,0) 3x4 filled with 0s

void combi(int ind, ll curr_grp, ll sum_far) {
  if (ind==nums.size()) {
    sums.insert(sum_far+curr_grp);
    return;
  }
  ll concat=stoll(to_string(curr_grp)+to_string(nums[ind]));
  combi(ind+1,concat,sum_far);
  combi(ind+1,nums[ind],sum_far+curr_grp);
};

void solve() {
  ll n;
  char c;
  while (true) {
    cin>>n;
    nums.push_back(n);
    if (!(cin>>c)) break;
  }
  combi(0,0,0);
  cout<<sums.size()<<endl;
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
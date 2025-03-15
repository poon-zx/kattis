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
  vector<int> cnt(n+2,0);
  vector<int> v(n);
  for (int i=0;i<n;i++) {
    cin>>v[i];
    if (i==n-1&&v[i]!=n+1) {
      cout<<"Error";
      return;
    }
    cnt[v[i]]++;
  }
  priority_queue<int,vector<int>,greater<int>> leaves;
  for (int i=1;i<cnt.size();i++) {
    if (cnt[i]==0) leaves.push(i);
  }
  vector<int> res;
  for (int i=0;i<n;i++) {
    if (leaves.empty()) {
      cout<<"Error\n";
      return;
    }
    int first=leaves.top();
    leaves.pop();
    res.push_back(first);
    cnt[v[i]]--;
    if (cnt[v[i]]==0) leaves.push(v[i]);
  }
  for (auto num:res) {
    cout<<num<<"\n";
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
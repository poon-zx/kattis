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

using i64 = long long;

constexpr int MOD = 1'000'000'007;

constexpr array<array<int, 2>, 4> directions{{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}};

// vector<vector<int>> v(3, vector<int>(4,0) 3x4 filled with 0s

struct Cup {
    int radius;
    string color;
};

void solve() {
  int n;
  cin>>n;
  vector<Cup> cups;

  for (int i=0;i<n;i++) {
    string t1,t2;
    cin>>t1>>t2;
    Cup cup;

    if (isdigit(t1[0])) {
      int d=stoi(t1);
      cup.radius=d/2;
      cup.color=t2;
    } else {
      cup.color=t1;
      cup.radius=stoi(t2);
    }
    cups.push_back(cup);
  }
  sort(cups.begin(),cups.end(),[](const Cup &a,const Cup &b) {
    return a.radius<b.radius;
  });

  for (const auto &cup:cups) {
    cout<<cup.color<<"\n";
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
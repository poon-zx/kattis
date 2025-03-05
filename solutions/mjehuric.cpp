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
  vector<int> v;
  int t;
  for (int i=0;i<5;i++) {
    cin>>t;
    v.push_back(t);
  }
  bool sorted=false;
  while (!sorted) {
    sorted=true;
    for (int i=0;i<v.size()-1;i++) {
      if (v[i+1]<v[i]) {
        sorted=false;
        int temp=v[i];
        v[i]=v[i+1];
        v[i+1]=temp;
        for (auto ele:v) {
          cout<<ele<<" ";
        }
        cout<<"\n";
      }
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
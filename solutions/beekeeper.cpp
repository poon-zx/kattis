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
  unordered_set<char> vowels={'a','e','i','o','u','y'};
  while (cin>>n&&n!=0) {
    string t;
    cin>>t;
    int curr=0;
    for (int i=0;i<t.size()-1;i++) {
      if (vowels.find(t[i])!=vowels.end()&&t[i]==t[i+1]) {
          curr++;
      }
    }
    int biggest=curr;
    string biggest_str=t;
    for (int i=1;i<n;i++) {
      cin>>t;
      curr=0;
      for (int j=0;j<t.size()-1;j++) {
        if (vowels.find(t[j])!=vowels.end()&&t[j]==t[j+1]) {
          curr++;
        }
      }
      if (curr>biggest) {
        biggest=curr;
        biggest_str=t;
      }
    }
    cout<<biggest_str<<endl;
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
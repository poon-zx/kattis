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
  unsigned int bits;
  cin>>oct>>bits;
  int played=bits&((1<<9)-1);
  int moves=(bits>>9)&((1<<9)-1);
  vector<int> winning={
    0b000000111,
    0b111000000,
    0b000111000,
    0b100100100,
    0b010010010,
    0b001001001,
    0b100010001,
    0b001010100
  };
  for (auto b:winning) {
    if ((played&b)==b) {
      if ((moves&b)==b) {
        cout<<"X wins"<<"\n";
        return;
      } else if ((moves&b)==0) {
        cout<<"O wins"<<"\n";
        return;
      }
    }
  }
  if (played==((1<<9)-1)) {
    cout<<"Cat's"<<"\n";
  } else {
    cout<<"In progress"<<"\n";
  }
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
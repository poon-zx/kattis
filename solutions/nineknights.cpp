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

constexpr array<array<int, 2>, 8> directions{{
    {-2, -1},
    {-2, 1},
    {1, -2},
    {1, 2},
    {2, -1},
    {2, 1},
    {-1, -2},
    {-1, 2}
}};

// vector<vector<int>> v(3, vector<int>(4,0) 3x4 filled with 0s

void solve() {
  vector<string> board;
  for (int i=0;i<5;i++) {
    string s;
    getline(cin,s);
    board.push_back(s);
  }
  int k=0;
  for (int i=0;i<5;i++) {
    for (int j=0;j<5;j++) {
      char curr=board[i][j];
      if (curr=='k') {
        for (auto &pair:directions) {
          int new_x=i+pair[0];
          int new_y=j+pair[1];
          
          if (new_x>=0&&new_x<5&&new_y>=0&&new_y<5&&board[new_x][new_y]=='k') {
            cout<<"invalid";
            return;
          }
        }
        k++;
      }
    }
  }
  if (k==9) {cout<<"valid";}
  else {cout<<"invalid";}
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
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
  // bitmask brute force
  char board[3][3];
  for (int i=0;i<3;i++) {
    for (int j=0;j<3;j++) {
      cin>>board[i][j];
    }
  }
  int ans=10;
  for (int mask=0;mask<(1<<9);mask++) {
    char temp[3][3];
    for (int i=0;i<3;i++) {
      for (int j=0;j<3;j++) {
        temp[i][j]='.';
      }
    }
    int clicks=0;
    for (int i=0;i<9;i++) {
      if (mask&(1<<i)) {
        clicks++;
        int x=i/3;
        int y=i%3;
        auto toggle = [&](int r,int c) {
            if (r>=0&&r<3&&c>=0&&c<3) {
              temp[r][c]=(temp[r][c]=='.')?'*':'.';
            }
        };
        toggle(x+1,y);
        toggle(x-1,y);
        toggle(x,y);
        toggle(x,y+1);
        toggle(x,y-1);
      }
    }
    bool correct=true;
    for (int i=0;i<3;i++) {
      for (int j=0;j<3;j++) {
        if (board[i][j]!=temp[i][j]) {
          correct=false;
        }
      }
    }
    if (correct) {ans=min(ans,clicks);}
  }
  cout<<ans<<"\n";
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
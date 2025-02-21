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

int valid(vector<vector<char>> v, int r, int c, bool first) {
  if (v[r][c]=='.') {
    if (first) {
      int res=0;
      if (r>=2&&v[r-1][c]=='o'&&v[r-2][c]=='o') {res++;}
      if (r<v.size()-2&&v[r+1][c]=='o'&&v[r+2][c]=='o') {res++;}
      if (c==2&&v[r][3]=='o'&&v[r][4]=='o') {res++;}
      if (c==4&&v[r][3]=='o'&&v[r][2]=='o') {res++;}
      return res;
    } else {
        int res=0;
      if (r>=2&&v[r-1][c]=='o'&&v[r-2][c]=='o') {res++;}
      if (r<v.size()-2&&v[r+1][c]=='o'&&v[r+2][c]=='o') {res++;}
      if (c>=2&&v[r][c-2]=='o'&&v[r][c-1]=='o') {res++;}
      if (c<v[0].size()-2&&v[r][c+1]=='o'&&v[r][c+2]=='o') {res++;}
      return res;
    }
  } else {return 0;}
}

// vector<vector<int>> v(3, vector<int>(4,0) 3x4 filled with 0s

void solve() {
  vector<vector<char>> v;
  for (int i=0;i<2;i++) {
    vector<char> temp = {'?','?'};
    for (int j=0;j<3;j++) {
      char c;
      cin>>c;
      temp.push_back(c);
    }
    temp.push_back('?');
    temp.push_back('?');
    v.push_back(temp);
  }
  for (int i=0;i<3;i++) {
    vector<char> temp;
    for (int j=0;j<7;j++) {
      char c;
      cin>>c;
      temp.push_back(c);
    }
    v.push_back(temp);
  }
  for (int i=0;i<2;i++) {
    vector<char> temp = {'?','?'};
    for (int j=0;j<3;j++) {
      char c;
      cin>>c;
      temp.push_back(c);
    }
    temp.push_back('?');
    temp.push_back('?');
    v.push_back(temp);
  }
  int res=0;
  for (int i=0;i<2;i++) {
    for (int j=2;j<5;j++) {
      res+=valid(v,i,j,true);
    }
  }
  for (int i=2;i<5;i++) {
    for (int j=0;j<7;j++) {
      res+=valid(v,i,j,false);
    }
  }
  for (int i=5;i<7;i++) {
    for (int j=2;j<5;j++) {
      res+=valid(v,i,j,true);
    }
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
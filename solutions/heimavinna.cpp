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
  string s;
  getline(cin,s);
  int res=0;
  string curr_num;
  string prev_num;
  bool to=false;
  for (auto ch:s) {
    if (ch=='-') {
      to=true;
      prev_num=curr_num;
      curr_num="";
    }
    else if (ch==';') {
      if (to) {
        res+=stoi(curr_num)-stoi(prev_num)+1;
        prev_num="";
        curr_num="";
        to=false;
      } else {
        res++;
        curr_num="";
      }
    }
    else {
      curr_num+=ch;
    }
  }
  if (to) {
    res+=stoi(curr_num)-stoi(prev_num)+1;
    prev_num="";
    curr_num="";
    to=false;
    } else {
    res++;
    curr_num="";
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
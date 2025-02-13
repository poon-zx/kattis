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

unordered_map<string,int> memo;

int bt(string s) {
  if (memo.find(s)!=memo.end()) {
    return memo[s];
  }
  int counter=0;
  for (int i=0;i<s.size();i++) {
    if (s[i]=='o') {counter++;}
  }
  int m=counter;
  for (int i=0;i<s.size()-1;i++) {
    if (s[i]=='o'&&s[i+1]=='o') {
      if (i>0&&s[i-1]=='-') {
        string temp=s;
        temp[i-1]='o';
        temp[i]='-';
        temp[i+1]='-';
        m=min(m,bt(temp));
      }
      if (i<s.size()-2&&s[i+2]=='-') {
        string temp2=s;
        temp2[i+2]='o';
        temp2[i+1]='-';
        temp2[i]='-';
        m=min(m,bt(temp2));
      }
    }
  }
  memo[s]=m;
  return m;
}

void solve() {
  string s;
  cin>>s;
  cout<<bt(s)<<"\n";
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
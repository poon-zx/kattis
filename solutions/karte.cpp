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
  cin>>s;
  vector<bool> p(14,false),k(14,false),h(14,false),t(14,false);
  int p_cnt=13,k_cnt=13,h_cnt=13,t_cnt=13;
  for(int i=0;i<s.size();i+=3) {
    char suit=s[i];
    int num=(s[i+1]-'0')*10+(s[i+2]-'0');
    if(suit=='P') {
      if(p[num]) {cout<<"GRESKA";return;}
      else p[num]=true;
      p_cnt--;
    } else if (suit=='K') {
      if(k[num]) {cout<<"GRESKA";return;}
      else k[num]=true;
      k_cnt--;
    } else if (suit=='H') {
      if(h[num]) {cout<<"GRESKA";return;}
      else h[num]=true;
      h_cnt--;
    } else {
      if(t[num]) {cout<<"GRESKA";return;}
      else t[num]=true;
      t_cnt--;
    }
  }
  cout<<p_cnt<<" "<<k_cnt<<" "<<h_cnt<<" "<<t_cnt;
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
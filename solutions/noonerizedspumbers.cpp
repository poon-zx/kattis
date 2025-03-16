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

bool isValid(string s) {
  return !(s.size()>1&&s[0]=='0');
}

void solve() {
  string x_str,op,y_str,eq,z_str;
  cin>>x_str>>op>>y_str>>eq>>z_str;
  ll x=stoll(x_str);
  ll y=stoll(y_str);
  ll z=stoll(z_str);
  for (int i=1;i<x_str.size();i++) {
    for (int j=1;j<y_str.size();j++) {
      string new_x_str=y_str.substr(0,j)+x_str.substr(i);
      string new_y_str=x_str.substr(0,i)+y_str.substr(j);
      if (isValid(new_x_str)&&isValid(new_y_str)) {
        ll new_x=stoll(new_x_str);
        ll new_y=stoll(new_y_str);
        if (op=="+") {
          if (new_x+new_y==z) {
            cout<<new_x_str<<" "<<op<<" "<<new_y_str<<" = "<<z_str<<"\n";
          }
        } else if (op=="*") {
          if (new_x*new_y==z) {
            cout<<new_x_str<<" "<<op<<" "<<new_y_str<<" = "<<z_str<<"\n";
          }
        }
      }
    }
  }
  for (int i=1;i<x_str.size();i++) {
    for (int j=1;j<z_str.size();j++) {
      string new_x_str=z_str.substr(0,j)+x_str.substr(i);
      string new_z_str=x_str.substr(0,i)+z_str.substr(j);
      if (isValid(new_x_str)&&isValid(new_z_str)) {
        ll new_x=stoll(new_x_str);
        ll new_z=stoll(new_z_str);
        if (op=="+") {
          if (new_x+y==new_z) {
            cout<<new_x_str<<" "<<op<<" "<<y_str<<" = "<<new_z_str<<"\n";
          }
        } else if (op=="*") {
          if (new_x*y==new_z) {
            cout<<new_x_str<<" "<<op<<" "<<y_str<<" = "<<new_z_str<<"\n";
          }
        }
      }
    }
  }
  for (int i=1;i<y_str.size();i++) {
    for (int j=1;j<z_str.size();j++) {
      string new_y_str=z_str.substr(0,j)+y_str.substr(i);
      string new_z_str=y_str.substr(0,i)+z_str.substr(j);
      if (isValid(new_y_str)&&isValid(new_z_str)) {
        ll new_y=stoll(new_y_str);
        ll new_z=stoll(new_z_str);
        if (op=="+") {
          if (x+new_y==new_z) {
            cout<<x_str<<" "<<op<<" "<<new_y_str<<" = "<<new_z_str<<"\n";
          }
        } else if (op=="*") {
          if (x*new_y==new_z) {
            cout<<x_str<<" "<<op<<" "<<new_y_str<<" = "<<new_z_str<<"\n";
          }
        }
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
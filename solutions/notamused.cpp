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
  int day=1;
  string s;
  while (cin>>s) {
    unordered_map<string, double> total;
    unordered_map<string, int> curr;
    while (true) {
      string f;
      cin>>f;
      if (f=="CLOSE") {break;}
      string name;
      int time;
      cin>>name>>time;
      if (f=="ENTER") {
        curr[name]=time;
      } else {
        if (total.find(name)==total.end()) {
          total[name]=0.0;
        }
        total[name]+=(time-curr[name])*0.10;
      }
    }
    vector<string> names;
    for (auto &it:total) {
      names.push_back(it.first);
    }
    sort(names.begin(),names.end());
    cout<<"Day "<<day<<"\n";
    day++;
    for (auto nam:names) {
      double amt=total[nam];
      cout<<nam<<" $";
      cout<<fixed<<setprecision(2)<<amt<<"\n";
    }
    cout<<"\n";
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
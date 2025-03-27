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
  while (true) {
    if (cin.peek()==EOF) break;
    vector<double> heart_rates;
    string name="";
    bool tokenFound=false;
    while (cin.peek()!='\n'&&cin.peek()!=EOF) {
      tokenFound=true;
      double d;
      if (cin>>d) heart_rates.push_back(d);
      else {
        cin.clear();
        string s;
        cin>>s;
        if (name.empty()) name=s;
        else name+=" "+s;
      }
    }
    if (!tokenFound) break;
    cin.ignore();
    double sum=0.0;
    for (double hr:heart_rates) sum+=hr;
    double average=(heart_rates.empty())?0.0:sum/heart_rates.size();
    cout<<fixed<<setprecision(2)<<average<<" "<<name<<"\n";
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
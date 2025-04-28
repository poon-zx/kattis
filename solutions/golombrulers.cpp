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
  while(getline(cin,s)) {
    istringstream iss(s);
    vector<int> v;
    int x;
    while (iss>>x) {
      v.push_back(x);
    }
    vector<int> diff_v(2001,0);
    bool found=false;
    int maxx=0;
    for (int i=0;i<v.size();i++) {
      for (int j=i+1;j<v.size();j++) {
        int diff=abs(v[j]-v[i]);
        maxx=max(maxx,diff);
        if (diff_v[diff]==1) {
          cout<<"not a ruler\n";
          found=true;
          break;
        } else diff_v[diff]++;
      }
      if(found) break;
    }
    if(found) continue;
    vector<int> missing;
    bool good=true;
    for (int i=1;i<=maxx;i++) {
      if(diff_v[i]==0) {
        missing.push_back(i);
        good=false;
      }
    }
    if(good) cout<<"perfect\n";
    else {
      cout<<"missing ";
      for (auto& num:missing) cout<<num<<" ";
      cout<<"\n";
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
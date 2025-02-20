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
  int n;
  cin>>n;
  vector<pair<string,int>> combos;
  for (int i=1;i<=20;i++) {
    combos.push_back({"single "+to_string(i),i});
    combos.push_back({"double "+to_string(i),i*2});
    combos.push_back({"triple "+to_string(i),i*3});
  }
  if (n<=60) {
    for (int i=0;i<combos.size();i++) {
      if (n==combos[i].second) {
        cout<<combos[i].first;
        return;
      }
    }
  }
  for (int i=0;i<combos.size();i++) {
    for (int j=i;j<combos.size();j++) {
      if(n==combos[i].second+combos[j].second) {
        cout<<combos[i].first<<"\n";
        cout<<combos[j].first<<"\n";
        return;
      }
    }
  }
  for (int i=0;i<combos.size();i++) {
    for (int j=i;j<combos.size();j++) {
      for (int k=j;k<combos.size();k++) {
        if(n==combos[i].second+combos[j].second+combos[k].second) {
            cout<<combos[i].first<<"\n";
            cout<<combos[j].first<<"\n";
            cout<<combos[k].first<<"\n";
            return;
        }
      }
    }
  }
  cout<<"impossible";
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
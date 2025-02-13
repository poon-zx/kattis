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
    int n,m;
    cin>>n>>m;
    if (n==0) {return;}
    vector<int> heads;
    vector<int> knights;
    for (int i=0;i<n;i++) {
      int h;
      cin>>h;
      heads.push_back(h);
    }
    for (int i=0;i<m;i++) {
      int h;
      cin>>h;
      knights.push_back(h);
    }
    sort(heads.begin(),heads.end());
    sort(knights.begin(),knights.end());
    int pointer=0;
    int coins=0;
    int head_cnt=0;
    for (auto &head:heads) {
      while (pointer<m) {
        int curr_knight=knights[pointer];
        if (curr_knight>=head) {
          coins+=curr_knight;
          head_cnt++;
          pointer++;
          break;
        } 
        pointer++;
      }
      if (pointer==m) {break;}
    }
    if (head_cnt!=n) {cout<<"Loowater is doomed!"<<"\n";}
    else {cout<<coins<<"\n";}
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
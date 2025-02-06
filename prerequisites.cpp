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

using i64 = long long;

constexpr int MOD = 1'000'000'007;

constexpr array<array<int, 2>, 4> directions{{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}};

// vector<vector<int>> v(3, vector<int>(4,0) 3x4 filled with 0s

void solve() {
  int k,m;
  while (cin>>k) {
    if (k==0) {return;}
    cin>>m;
    unordered_set<string> us;
    string s;
    bool meet=true;
    for (int i=0;i<k;i++) {
      cin>>s;
      us.insert(s);
    }
    int total,min;
    
    for (int i=0;i<m;i++) {
      cin>>total>>min;
      int counter=0;
      string curr;
      for (int j=0;j<total;j++) {
        cin>>curr;
        if (us.find(curr)!=us.end()) {
          counter++;
        }
      }
      if (counter<min) {
        meet=false;
      }
    }
    if (meet) {cout<<"yes\n";}
    else {cout<<"no\n";}
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
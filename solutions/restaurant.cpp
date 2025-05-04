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
  while(cin>>n&&n!=0) {
    int first=0;
    int second=0;
    for (int i=0;i<n;i++) {
      string s;
      int a;
      cin>>s>>a;
      if(s=="DROP") {
        second+=a;
        cout<<"DROP 2 "<<a<<"\n";
      } else {
        if(first==0) {
          first=second;
          cout<<"MOVE 2->1 "<<second<<"\n";
          second=0;
          first-=a;
          cout<<"TAKE 1 "<<a<<"\n";
        } else if(a>first) {
          cout<<"TAKE 1 "<<first<<"\n";
          int diff=a-first;
          first=second;
          cout<<"MOVE 2->1 "<<second<<"\n";
          second=0;
          first-=diff;
          cout<<"TAKE 1 "<<diff<<"\n";
        } else {
          first-=a;
          cout<<"TAKE 1 "<<a<<"\n";
        }
      }
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
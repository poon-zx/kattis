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
  while (cin>>n&&n!=0) {
    string res="????????????????????????????????";
    for (int i=0;i<n;i++) {
      string s;
      cin>>s;
      int a,b;
      if (s=="SET") {
        cin>>a;
        res[a]='1';
      } else if (s=="CLEAR") {
        cin>>a;
        res[a]='0';
      } else if (s=="OR") {
        cin>>a>>b;
        if (res[a]!='?'&&res[b]!='?') res[a]=char(((res[a]-'0')|(res[b]-'0'))+'0');
        else if (res[a]=='1'||res[b]=='1') res[a]='1';
        else res[a]='?';
      } else {
        cin>>a>>b;
        if (res[a]!='?'&&res[b]!='?') res[a]=char(((res[a]-'0')&(res[b]-'0'))+'0');
        else if (res[a]=='0'||res[b]=='0') res[a]='0';
        else res[a]='?';
      }
    }
    reverse(res.begin(),res.end());
    cout<<res<<"\n";
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
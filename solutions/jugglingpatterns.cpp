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
    int sum=0;
    vector<int> v(s.size());
    int n=v.size();
    for (int i=0;i<n;i++) {
      int curr=s[i]-'0';
      v[i]=curr;
      sum+=curr;
    }
    if(sum%v.size()!=0) {
      cout<<s<<": invalid # of balls"<<endl;
      continue;
    }
    vector<bool> seen(n, false);
    bool valid=true;
    for (int i=0;i<n;i++) {
       if(seen[(i+v[i])%n]) {valid=false;break;}
       seen[(i+v[i])%n]=true;
    }
    if(!valid) cout<<s<<": invalid pattern"<<endl;
    else cout<<s<<": valid with "<<sum/v.size()<<" balls"<<endl;
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
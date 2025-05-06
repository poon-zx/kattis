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
  int n,p,m;
  cin>>n>>p>>m;
  unordered_map<string,int> ma;
  for(int i=0;i<n;i++) {
    string s;
    cin>>s;
    ma[s]=0;
  }
  bool won=false;
  for(int i=0;i<m;i++) {
    string s;
    int a;
    cin>>s>>a;
    if(ma.find(s)==ma.end()) continue;
    ma[s]+=a;
    if(ma[s]>=p) {won=true;cout<<s<<" wins!\n";ma.erase(s);}
  }
  if(!won) cout<<"No winner!";
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
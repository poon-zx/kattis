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
  getline(cin,s);
  istringstream iss(s);
  int k=0;
  string w;
  while(iss>>w) k++;
  int n;
  cin>>n;
  vector<string> v(n);
  for (int i=0;i<n;i++) cin>>v[i];
  vector<string> team1;
  vector<string> team2;
  bool first=true;
  int curr=0;
  for (int i=0;i<n;i++) {
    curr+=k-1;
    curr%=v.size();
    if(first) team1.push_back(v[curr]);
    else team2.push_back(v[curr]);
    first=!first;
    v.erase(v.begin()+curr);
  }
  cout<<team1.size()<<"\n";
  for (auto& str:team1) cout<<str<<"\n";
  cout<<team2.size()<<"\n";
  for (auto& str:team2) cout<<str<<"\n";
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
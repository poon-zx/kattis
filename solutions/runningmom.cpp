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

unordered_map<string,vector<string>> mapp;
unordered_map<string,int> visited;

bool hasCycle(string s) {
  visited[s]=-1;
  for (auto& nei:mapp[s]) {
    if (visited[nei]==-1) {
      return true;
    } else if (visited[nei]==0&&hasCycle(nei)) {
      return true;
    }
  }
  visited[s]=1;
  return false;
}

void solve() {
  int n;
  cin>>n;
  for (int i=0;i<n;i++) {
    string s1,s2;
    cin>>s1>>s2;
    if (mapp.find(s1)==mapp.end()) mapp[s1]=vector<string>();
    mapp[s1].push_back(s2);
    visited[s1]=0;
    visited[s2]=0;
  }
  string s;
  while (cin>>s) {
    for (auto& it:visited) {
      it.second=0;
    }
    cout<<s<<" ";
    if (hasCycle(s)) cout<<"safe\n";
    else cout<<"trapped\n";
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
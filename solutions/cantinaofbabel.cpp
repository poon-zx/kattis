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

struct character{string name; string speaks; vector<string> understand;};

void solve() {
  int n;
  cin>>n;
  cin.ignore();
  vector<character> v(n);
  unordered_map<string,vector<string>> m;
  for(int i=0;i<n;i++) {
    string s;
    getline(cin,s);
    stringstream ss(s);
    string name;
    ss>>name;
    string speaks;
    ss>>speaks;
    m[speaks].push_back(name);
    v[i]=character(name,speaks,vector<string>());
    string lang;
    while(ss>>lang) {
      v[i].understand.push_back(lang);
      m[lang].push_back(name);
    }
  }
  unordered_map<string,vector<string>> adjList;
  for(auto &c:v) {
    for(auto &name:m[c.speaks]) {
      if(name!=c.name) adjList[c.name].push_back(name);
    }
  }
  // --- Kosaraju passes ---
  // 1) build transpose
  unordered_map<string, vector<string>> revList;
  for(auto &p : adjList)
    for(auto &dst : p.second)
      revList[dst].push_back(p.first);

  // 2) first DFS to get finish order
  vector<string> order;
  unordered_set<string> visited;
  function<void(const string&)> dfs1 = [&](auto &u){
    visited.insert(u);
    for(auto &w : adjList[u])
      if(!visited.count(w))
        dfs1(w);
    order.push_back(u);
  };
  for(auto &p : adjList)
    if(!visited.count(p.first))
      dfs1(p.first);

  // 3) second DFS on transpose, in reverse order
  visited.clear();
  int maxScc = 0;
  function<int(const string&)> dfs2 = [&](auto &u){
    visited.insert(u);
    int cnt = 1;
    for(auto &w : revList[u])
      if(!visited.count(w))
        cnt += dfs2(w);
    return cnt;
  };
  for(int i = order.size()-1; i >= 0; --i){
    auto &u = order[i];
    if(!visited.count(u)){
      maxScc = max(maxScc, dfs2(u));
    }
  }
  cout << (n - maxScc) << "\n"; 
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
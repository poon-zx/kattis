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

void toposort(string s, unordered_map<string,vector<string>> &adjList, unordered_set<string> &visited, vector<string> &res) {
  visited.insert(s);
  for (auto &nei:adjList[s])
    if (visited.find(nei)==visited.end()) toposort(nei,adjList,visited,res);
  res.push_back(s);                               
}

void solve() {
  int n;
  cin>>n;
  cin.ignore();
  unordered_map<string,vector<string>> adjList;
  while(n--) {
    string s;
    getline(cin,s);
    stringstream ss(s);
    string a;
    string main;
    while(ss>>a) {
      if(a.back()==':') {
        main=a.substr(0,a.size()-1);
      } else {
        adjList[a].push_back(main);
      }
    }
  }
  vector<string> res;
  unordered_set<string> visited;
  string f;
  cin>>f;
  toposort(f,adjList,visited,res);
  reverse(res.begin(),res.end());
  for(auto &str:res) cout<<str<<"\n";
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
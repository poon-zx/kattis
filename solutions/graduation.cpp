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

struct DSU {
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    int find(int a) {
        if (parent[a] != a)
            parent[a] = find(parent[a]);
        return parent[a];
    }
    
    bool union_set(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
        return true;
    }
};

void solve() {
  int line,col,clas;
  cin>>line>>col>>clas;
  DSU dsu(clas);
  vector<vector<char>> v(line,vector<char>(col));
  for (int i=0;i<line;i++) {
    for (int j=0;j<col;j++) {
      cin>>v[i][j];
    }
  }
  for (int j=0;j<col;j++) {
    unordered_set<char> char_set={};
    for (int i=0;i<line;i++) {
      if (char_set.find(v[i][j])==char_set.end()) {
        for (char elem:char_set) {
          dsu.union_set(elem-'A',v[i][j]-'A');
        }
        char_set.insert(v[i][j]);
      }
    }
  }
  unordered_set<int> sets;
  for (int i=0;i<clas;i++) {
    sets.insert(dsu.find(i));
  }
  cout<<sets.size();
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
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
    vector<int> parent, rank, sz;
    
    DSU(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        sz.assign(n,1);
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
        sz[a] += sz[b];
        if (rank[a] == rank[b])
            rank[a]++;
        return true;
    }

    int size(int a) {return sz[find(a)];}
};

void solve() {
  int n,l;
  cin>>n>>l;
  DSU dsu(l+1);
  for(int i=0;i<n;i++) {
    int a,b;
    cin>>a>>b;
    if(dsu.find(a)!=dsu.find(b)) dsu.union_set(a,b);
    if(dsu.size(a)>0) {
      dsu.sz[dsu.find(a)]--;
      cout<<"LADICA"<<"\n";
    } else cout<<"SMECE"<<"\n";
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
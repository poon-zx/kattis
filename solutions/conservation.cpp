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
  int n,m;
  cin>>n>>m;
  vector<int> stages(n+1);
  for(int i=1;i<=n;i++) cin>>stages[i];
  vector<vector<int>> adjList(n+1);
  vector<int> indeg0(n+1,0);
  for(int i=0;i<m;i++) {
    int a,b;
    cin>>a>>b;
    adjList[a].push_back(b);
    indeg0[b]++;
  }
  // two queue kahn's
  auto run=[&](int start_lab) {
    vector<int> indeg = indeg0;
    deque<int> q1;
    deque<int> q2;
    for(int i=1;i<=n;i++) {
      if(indeg[i]==0) {
        if(stages[i]==1) q1.push_back(i);
        else q2.push_back(i);
      }
    }
    if(q1.empty()) start_lab=2;
    int res=0;
    while(!q1.empty()||!q2.empty()) {
      deque<int> &q=(start_lab==1?q1:q2);
      if (start_lab==1) {
        if(q1.empty()) {
            start_lab=2;
            res++;
            continue;
        }
        } else {
        if(q2.empty()) {
            start_lab=1;
            res++;
            continue;
        }
        }
        int top=q.front();
        q.pop_front();
        for(auto &x:adjList[top]) {
        indeg[x]--;
        if(indeg[x]==0) {
            if(stages[x]==1) q1.push_back(x);
            else q2.push_back(x);
        }
        }
    }
    return res;
  };
  int ans1=run(1);
  int ans2=run(2);
  cout<<min(ans1,ans2)<<"\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tc;
  cin>>tc;
  while (tc--) {
    solve();
  }

  return 0;
}
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
  cin>>n;
  vector<pair<int,int>> students;
  for (int i=0;i<n;i++) {
    int x,y;
    cin>>x>>y;
    students.push_back({x,y});
  }
  unordered_set<int> visited;
  ll res=0;
  priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;
  pq.push({0,0});
  while (visited.size()<n) {
    pair<double,int> top=pq.top();
    pq.pop();
    if (visited.find(top.second)!=visited.end()) continue;
    //cout<<top.second<<" ";
    visited.insert(top.second);
    res+=top.first*2;
    for (int i=0;i<n;i++) {
      if (visited.find(i)==visited.end()) {
        pq.push({abs(students[top.second].first-students[i].first)+abs(students[top.second].second-students[i].second),i});
      }
    }
  }
  cout<<res;
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
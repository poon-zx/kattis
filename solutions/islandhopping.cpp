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

struct Point {
  double x,y;
};

void solve() {
  // Prim's
  int n;
  cin>>n;
  vector<Point> v(n);
  for (int i=0;i<n;i++) {
    cin>>v[i].x>>v[i].y;
  }
  vector<double> minDists(n,1e9);
  vector<bool> seen(n,false);
  priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;
  pq.push({0.0,0});
  minDists[0]=0.0;
  double total=0.0;
  while (!pq.empty()) {
    auto [d,i]=pq.top();
    pq.pop();
    if (seen[i]) {continue;}
    seen[i]=true;
    total+=d;
    for (int j=0;j<n;j++) {
      if (!seen[j]) {
        double xdist=abs(v[i].x-v[j].x);
        double ydist=abs(v[i].y-v[j].y);
        double totaldist=sqrt(xdist*xdist+ydist*ydist);
        if (totaldist<minDists[j]) {
          pq.push({totaldist,j});
          minDists[j]=totaldist;
        }
      }
    }
  }
  cout<<fixed<<setprecision(3)<<total<<"\n";


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
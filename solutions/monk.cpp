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

double get_height(const vector<double>& prefix_times, const vector<double>& prefix_heights, const vector<double>& rates, double t) {
  int i=int(upper_bound(prefix_times.begin(),prefix_times.end(),t)-prefix_times.begin())-1;
  double dt=t-prefix_times[i];
  return prefix_heights[i]+dt*rates[i];
}

void solve() {
  int a,d;
  cin>>a>>d;
  vector<double> up_h(a),up_t(a),up_rate(a);
  vector<double> down_h(d),down_t(d),down_rate(d);
  for (int i=0;i<a;i++) {
    cin>>up_h[i]>>up_t[i];
    up_rate[i]=up_h[i]/up_t[i];
  }
  for (int i=0;i<d;i++) {
    cin>>down_h[i]>>down_t[i];
    down_rate[i]=down_h[i]/down_t[i];
  }
  vector<double> up_time(a+1,0),up_height(a+1,0);
  for (int i=0;i<a;i++) {
    up_time[i+1]=up_time[i]+up_t[i];
    up_height[i+1]=up_height[i]+up_h[i];
  }
  vector<double> down_time(d+1,0),down_height(d+1,0);
  for (int i=0;i<d;i++) {
    down_time[i+1]=down_time[i]+down_t[i];
    down_height[i+1]=down_height[i]+down_h[i];
  }
  double h_total=up_height[a];
  double t_up=up_time[a];
  double t_down=down_time[d];
  double t=min(t_up,t_down);
  double lo=0,hi=t;
  for (int i=0;i<80;i++) {
    double mid=0.5*(lo+hi);
    double hu=get_height(up_time,up_height,up_rate,mid);
    double hd_desc=get_height(down_time,down_height,down_rate,mid);
    double hd=h_total-hd_desc;
    if(hu<hd) lo=mid;
    else hi=mid;
  }
  cout<<fixed<<setprecision(6)<<0.5*(lo+hi)<<"\n";
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
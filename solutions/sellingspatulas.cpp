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
  const double EPS=1e-9;
  while (cin>>n&&n!=0) {
    vector<int> t(n);
    vector<double> b(n);
    for (int i=0;i<n;i++) cin>>t[i]>>b[i];
    double best_sum=-1e18;
    int best_s=0,best_e=0;
    double curr_sum=0;
    int curr_s=0;
    for (int i=0;i<n;i++) {
      if (i==0) {
        curr_sum=b[i]-0.08;
        curr_s=0;
      } else {
        double w_start=b[i]-0.08;
        double w_cont=b[i]-0.08*(t[i]-t[i-1]);
        if (curr_sum+w_cont>w_start+EPS) {
          curr_sum+=w_cont;
        } else {
          curr_sum=w_start;
          curr_s=i;
        }
      }
      bool better=false;
      if (curr_sum>best_sum+EPS) {
        better=true;
      } else if (fabs(curr_sum-best_sum)<EPS) {
        int len_curr=t[i]-t[curr_s];
        int len_best=t[best_e]-t[best_s];
        if (len_curr<len_best||(len_curr==len_best&&t[curr_s]<t[best_s])) better=true;
      }
      if(better) {
        best_sum=curr_sum;
        best_s=curr_s;
        best_e=i;
      }
    }
    if (best_sum>EPS) {
      cout<<fixed<<setprecision(2)<<best_sum<<" "<<t[best_s]<<" "<<t[best_e]<<"\n";
    } else cout<<"no profit\n";
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
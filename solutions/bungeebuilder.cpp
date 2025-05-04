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

stack<pair<int,int>> s;
int max_jump=0;

void process_mountain(int m, vector<int> &v) {
  int max_j_at_m=0;
  while (v[m]>=s.top().first){
    max_j_at_m=max(v[m]-s.top().first+s.top().second,max_j_at_m);
    s.pop();
    if(s.empty())break;
  }
  s.push({v[m],max_j_at_m});
  max_jump=max(max_jump,max_j_at_m);
}

void solve() {
  int n;
  cin>>n;
  vector<int> v(n);
  int max_h=0,max_h_pos=-1;
  for (int i=0;i<n;i++) {
    cin>>v[i];
    if(v[i]>max_h) {
      max_h_pos=i;
      max_h=v[i];
    }
  }
  s.push({max_h,0});
  int res=0;
  for(int i=max_h_pos-1;i>=0;i--) process_mountain(i,v);
  while(!s.empty())s.pop();
  s.push({max_h,0});
  for(int i=max_h_pos+1;i<n;i++) process_mountain(i,v);
  cout<<max_jump;
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
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
  int first;
  cin>>first;
  vector<int> diff(n-1);
  vector<int> nums(n);
  nums[0]=first;
  for(int i=0;i<n-1;i++) {
    int a;
    cin>>a;
    nums[i+1]=a;
    diff[i]=a-first;
    //cout<<diff[i]<<" ";
    first=a;
  }
  bool ari=true;
  for(int i=0;i<diff.size()-1;i++) {
    if(diff[i]!=diff[i+1]) ari=false;
  }
  if(ari) {cout<<"arithmetic"<<"\n";return;}
  sort(nums.begin(),nums.end());
  bool og=true;
  int difff=nums[1]-nums[0];
  for(int i=1;i<n-1;i++) {
    if(nums[i+1]-nums[i]!=difff) og=false;
  }
  if(og) cout<<"permuted arithmetic"<<"\n";
  else cout<<"non-arithmetic"<<"\n";
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
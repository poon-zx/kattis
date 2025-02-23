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

vector<int> v(6);
int h1,h2;

vector<int> backtrack(int sum, deque<int> curr, vector<int> left) {
  if (curr.size()==3) {
    if (sum==0) {
      vector<int> result(curr.begin(),curr.end());
      return result;
    }
    else {return {};}
  }
  for (int i=0;i<left.size();i++) {
    curr.push_back(left[i]);
    int new_sum=sum-left[i];
    vector<int> new_left=left;
    new_left.erase(new_left.begin()+i);
    vector<int> res=backtrack(new_sum,curr,new_left);
    curr.pop_back();
    if (!res.empty()) {return res;}
  }
  return {};
}

void solve() {
  for (int i=0;i<6;i++) {
    cin>>v[i];
  }
  cin>>h1>>h2;
  sort(v.begin(),v.end(),greater<int>());
  deque<int> d;
  vector<int> v1=backtrack(h1,d,v);
  set<int> sett(v1.begin(),v1.end());
  vector<int> v2;
  vector<int> v3;
  for (int i=0;i<6;i++) {
    if (sett.find(v[i])==sett.end()) {
      v3.push_back(v[i]);
    } else {
      v2.push_back(v[i]);
    }
  }
  for (int i=0;i<v2.size();i++) {
    cout<<v2[i]<<" ";
  }
  for (int i=0;i<v3.size();i++) {
    cout<<v3[i]<<" ";
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
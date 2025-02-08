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

using i64 = long long;

constexpr int MOD = 1'000'000'007;

constexpr array<array<int, 2>, 4> directions{{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}};

// vector<vector<int>> v(3, vector<int>(4,0) 3x4 filled with 0s

void solve(int tc) {
  int n;
  string a;
  cin>>n;
  deque<int> b,r;
  for (int i=0;i<n;i++) {
    cin>>a;
    if (a.back()=='B') {
      b.push_back(stoi(a.substr(0,a.size()-1)));
    } else {
      r.push_back(stoi(a.substr(0,a.size()-1)));
    }
  }
  sort(b.begin(),b.end(),greater<int>());
  sort(r.begin(),r.end(),greater<int>());
  int res=0;
  while (!b.empty()&&!r.empty()) {
    res+=b.front()-1;
    b.pop_front();
    res+=r.front()-1;
    r.pop_front();
  }
  cout<<"Case #"<<tc+1<<": "<<res<<"\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tc;
  cin>>tc;
  for (int i=0;i<tc;i++) {
    solve(i);
  }

  return 0;
}
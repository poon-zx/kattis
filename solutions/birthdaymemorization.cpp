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

void solve() {
  int n;
  cin>>n;
  unordered_map<string,pair<string,int>> m;
  for (int i=0;i<n;i++) {
    string name,bday;
    int l;
    cin>>name>>l>>bday;
    if (m.find(bday)==m.end()) {
      pair<string,int> temp={name,l};
      m[bday]=temp;
    } else {
      if (l>m[bday].second) {
        m[bday]={name,l};
      }
    }
  }
  vector<string> names;
  for (auto &it:m) {
    names.push_back(it.second.first);
  }
  sort(names.begin(),names.end());
  cout<<names.size()<<"\n";
  for (int i=0;i<names.size();i++) {
    cout<<names[i]<<"\n";
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
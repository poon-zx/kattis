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
  int n,a;
  cin>>n>>a;
  unordered_map<string,bool> m;
  for (int i=0;i<n;i++) {
    string s;
    cin>>s;
    if (i==0) {
      m[s]=true;
    } else {
      m[s]=false;
    }
  }
  unordered_set<string> v;
  for (int i=0;i<a;i++) {
    string a,b,c;
    cin>>a>>b>>c;
    if (!m[a]) {
      v.insert(a);
      m[c]=true;
    } else {
      m[a]=false;
      m[c]=true;
    }
  }
  vector<string> vect;
  for (auto &str:v) {
    vect.push_back(str);
  }
  sort(vect.begin(),vect.end());
  cout<<v.size()<<"\n";
  for (int i=0;i<vect.size();i++) {
    cout<<vect[i];
    if (i!=vect.size()-1) {
      cout<<" ";
    }
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
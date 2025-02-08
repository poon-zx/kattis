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
  float d;
  int n;
  while (cin>>d>>n) {
    if (n==0) {
      return;
    }
    vector<vector<float>> v;
    for (int i=0;i<n;i++) {
      float a,b;
      cin>>a>>b;
      v.push_back({a,b});
    }
    vector<bool> sour(n,false);
    for (int i=0;i<n;i++) {
      for (int j=i+1;j<n;j++) {
        float dist=sqrt(pow(v[i][0]-v[j][0],2)+pow(v[i][1]-v[j][1],2));
        // cout<<dist<<" "<<i<<" "<<j<<" ";
        if (dist<d) {
          sour[i]=true;
          sour[j]=true;
          break;
        }
      }
    }
    int res=0;
    for (int i=0;i<n;i++) {
      if (sour[i]) {
        res++;
      }
    }
    cout<<res<<" sour, "<<n-res<<" sweet\n";
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
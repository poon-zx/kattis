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
  int n,m;
  cin>>n>>m;
  vector<int> rank(n);
  unordered_map<int,int> pos;
  for (int i=0;i<n;i++) {
    rank[i]=i+1;
    pos[i+1]=i;
  }
  for (int i=0;i<m;i++) {
    string t1,t2;
    cin>>t1>>t2;
    int team1=stoi(t1.substr(1));
    int team2=stoi(t2.substr(1));
    int pos1=pos[team1];
    int pos2=pos[team2];
    //cout<<pos1<<" "<<pos2<<" ";
    if (pos1<pos2) continue;
    for (int j=pos2;j<pos1;j++) {
      rank[j]=rank[j+1];
      pos[rank[j]]--;
    }
    rank[pos1]=team2;
    pos[team2]=pos1;
    //cout<<pos[team1]<<" "<<pos[team2];
  }
  for (auto i:rank) {
    cout<<'T'<<i<<" ";
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
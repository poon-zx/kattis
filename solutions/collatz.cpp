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
#include <chrono>

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

vector<ll> collatz_path(ll x) {
  vector<ll> seq;
  seq.push_back(x);
  while(x!=1) {
    if(x%2==0) x/=2;
    else x=3*x+1;
    seq.push_back(x);
  }
  return seq;
}

// vector<vector<int>> v(3, vector<int>(4,0) 3x4 filled with 0s

void solve() {
  int a,b;
  while(cin>>a>>b&&a!=0) {
    auto seqA=collatz_path(a);
    auto seqB=collatz_path(b);
    int lenA=seqA.size();
    int lenB=seqB.size();
    int i=0,j=0;
    if(lenA>lenB) i=lenA-lenB;
    else j=lenB-lenA;
    while(seqA[i]!=seqB[j]) {
      i++;
      j++;
    }
    cout<<a<<" needs "<<i<<" steps, "<<b<<" needs "<<j<<" steps, they meet at "<<seqA[i]<<"\n";
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
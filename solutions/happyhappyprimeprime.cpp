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

bool isprime(int n) {
  if (n<2) {return false;}
  if (n==2) {return true;}
  if (n%2==0) {return false;}
  for (int i=3;(i*i)<=n;i+=2) {
    if (n%i==0) {
      return false;
    }
  }
  return true;
}

void solve() {
  int tc,num;
  cin>>tc>>num;
  if (!isprime(num)) {
    cout<<tc<<" "<<num<<" "<<"NO\n";
    return;
  }
  int n=num;
  unordered_set<int> set;
  while (n!=1) {
    set.insert(n);
    int sum=0;
    while (n!=0) {
      sum+=(n%10)*(n%10);
      n/=10;
    }
    if (set.find(sum)!=set.end()) {
      cout<<tc<<" "<<num<<" "<<"NO\n";
      return;
    }
    n=sum;
  }
  cout<<tc<<" "<<num<<" "<<"YES\n";
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
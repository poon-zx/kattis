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
  int n,t;
  cin>>n>>t;
  vector<ll> v(n);
  for (int i=0;i<n;i++) cin>>v[i];
  if (t==1) {
    sort(v.begin(),v.end());
    int l=0,r=n-1;
    while (l<r) {
      if (v[l]+v[r]==7777) {
        cout<<"Yes";
        return;
      } else if (v[l]+v[r]<7777) {
        l++;
      } else r--;
    }
    cout<<"No";
  } else if (t==2) {
    unordered_set<ll> sett;
    for (auto& num:v) sett.insert(num);
    cout<<((sett.size()==n)?"Unique":"Contains duplicate");
  } else if (t==3) {
    unordered_map<ll,ll> mapp;
    for (auto& num:v) {
      mapp[num]++;
      if (mapp[num]>n/2) {
        cout<<num;
        return;
      }
    }
    cout<<-1;
  } else if (t==4) {
    sort(v.begin(),v.end());
    if (n%2==1) cout<<v[n/2];
    else cout<<v[n/2-1]<<" "<<v[n/2];
  } else {
    sort(v.begin(),v.end());
    for (auto& num:v) {
      if (num>999) break;
      if (num>=100) cout<<num<<" ";
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
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
  cin.ignore();
  // map to map name to set of words
  // map to count words
  // sort vector at the end

  unordered_map<string,unordered_set<string>> map1;
  unordered_map<string,int> map2;
  while(n--) {
    string s;
    getline(cin,s);
    stringstream ss(s);
    string s1,name;
    ss>>name;
    while(ss>>s1) {
      map1[name].insert(s1);
      map2[s1]++;
    }
  }
  vector<pair<int,string>> ve;
  for(auto &[k,v]:map2) {
    bool all=true;
    for(auto &[s,se]:map1) {
      if(se.find(k)==se.end()) {all=false;break;}
    }
    if(all) ve.push_back({v,k});
  }
  sort(ve.begin(),ve.end(),[](auto &a,auto &b) {
    if(a.first!=b.first) return a.first>b.first;
    else return a.second<b.second; 
  });
  if(ve.empty()) cout<<"ALL CLEAR";
  else for(auto &[k,v]:ve) cout<<v<<"\n";
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
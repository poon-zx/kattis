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
  priority_queue<pair<int,int>> buy;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> sell;
  int pricee=-1;
  for (int i=0;i<n;i++) {
    string s,x,y;
    int num,price;
    cin>>s>>num>>x>>y>>price;
    if(s=="buy") buy.push({price,num});
    else sell.push({price,num});
    while(!buy.empty()&&!sell.empty()&&buy.top().first>=sell.top().first) {
      auto [b_p,b_n]=buy.top();
      buy.pop();
      auto [s_p,s_n]=sell.top();
      sell.pop();
      int amt=min(b_n,s_n);
      pricee=s_p;
      b_n-=amt;
      s_n-=amt;
      if(b_n>0) buy.push({b_p,b_n});
      if(s_n>0) sell.push({s_p,s_n});
    }
    cout<<(sell.empty()?"-":to_string(sell.top().first))<<" ";
    cout<<(buy.empty()?"-":to_string(buy.top().first))<<" ";
    cout<<(pricee==-1?"-":to_string(pricee))<<endl;
  }
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
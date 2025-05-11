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
  string s;
  unordered_map<string,int> s_to_int;
  unordered_map<int,string> int_to_s;
  while(cin>>s) {
    if(s=="def") {
      string var;
      cin>>var;
      if(s_to_int.find(var)!=s_to_int.end()) {
        int curr=s_to_int[var];
        int_to_s.erase(curr);
      }
      int n;
      cin>>n;
      s_to_int[var]=n;
      int_to_s[n]=var;
    } else if(s=="calc"){
      vector<string> vars;
      vector<char> eqs;
      string var;
      char eq;
      bool unknown=false;
      while(true) {
        cin>>var>>eq;
        if(s_to_int.find(var)==s_to_int.end()) unknown=true;
        vars.push_back(var);
        if(eq=='=') break;
        eqs.push_back(eq);
      }
      string res;
      if(!unknown) {
        int curr=s_to_int[vars[0]];
        for(int i=1;i<vars.size();i++) {
          if(eqs[i-1]=='+') curr+=s_to_int[vars[i]];
          else curr-=s_to_int[vars[i]];
        }
        if(int_to_s.find(curr)==int_to_s.end()) {
          unknown=true;
        } else {
          res=int_to_s[curr];
        }
      }
      if(unknown) res="unknown";
      for(int i=0;i<vars.size()-1;i++) {
        cout<<vars[i]<<" "<<eqs[i]<<" ";
      }
      
      cout<<vars.back()<<" = "<<res<<"\n";
    } else {
      s_to_int.clear();
      int_to_s.clear();
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
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
  unordered_map<string,vector<int>> cars;
  for(int i=0;i<n;i++) {
    string N;
    int p,q,k;
    cin>>N>>p>>q>>k;
    cars[N]={p,q,k};
  }
  map<string,ll> res;
  unordered_map<string,bool> inconsistent;
  unordered_map<string,string> current_car;
  for(int i=0;i<m;i++) {
    int t;
    string name;
    char c;
    cin>>t>>name>>c;
    if(res.find(name)==res.end()) res[name]=0LL;
    if(inconsistent.find(name)==inconsistent.end()) inconsistent[name]=false;
    if(c=='p') {
      string car_name;
      cin>>car_name;
      if(current_car.find(name)!=current_car.end()) {
        inconsistent[name]=true;
      } else {
        current_car[name]=car_name;
        res[name]+=(ll)cars[car_name][1];
      }
    } else if(c=='r') {
      int dist;
      cin>>dist;
      if(current_car.find(name)==current_car.end()) {
        inconsistent[name]=true;
      } else {
        string car_name=current_car[name];
        res[name]+=(ll)cars[car_name][2]*(ll)dist;
        current_car.erase(name);
      }
    } else {
      int severity;
      cin>>severity;
      if(current_car.find(name)==current_car.end()) {
        inconsistent[name]=true;
      } else {
        string car_name=current_car[name];
        ll curr=(ll)cars[car_name][0]*(ll)severity;
        //cout<<name<<" "<<car_name<<" "<<curr<<"\n";
        curr=(curr+99LL)/100LL;
        res[name]+=curr;
      }
    }
  }
  for(auto &[x,y]:current_car) inconsistent[x]=true;
  for(auto &[x,y]:res) {
    if(inconsistent[x]) cout<<x<<" INCONSISTENT";
    else cout<<x<<" "<<y;
    cout<<"\n";
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
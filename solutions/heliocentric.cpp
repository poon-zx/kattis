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

// Extended Euclidean Algorithm to compute gcd and the coefficients x and y for Bézout's identity: ax + by = gcd(a, b)
int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int gcd = extended_gcd(b, a % b, y, x);
    y -= (a / b) * x;
    return gcd;
}

// Function to compute modular inverse of a modulo m
int mod_inverse(int a, int m) {
    int x, y;
    int g = extended_gcd(a, m, x, y);
    if (g != 1) {
        // In our problem, this should never happen since a and m are coprime
        return -1;
    }
    // Make sure the result is positive
    x = (x % m + m) % m;
    return x;
}

void solve() {
  int e,m;
  int caseNum=1;
  while (cin>>e>>m) {
    int r1=((-e)%365+365)%365;
    int r2=((-m)%687+687)%687;
    int n1=365,n2=687;
    int N=n1*n2;
    int N1=N/n1;
    int N2=N/n2;
    int M1=mod_inverse(N1,n1);
    int M2=mod_inverse(N2,n2);
    //CRT formula
    ll d=((ll)r1*M1*N1+(ll)r2*M2*N2)%N;
    cout<<"Case "<<caseNum++<<": "<<d<<"\n";
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
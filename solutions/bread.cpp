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

long long merge_count(vector<int>& A, int l, int r) {
    if (r - l <= 1) return 0;
    int m = (l + r) / 2;
    long long inv = merge_count(A, l, m)
                  + merge_count(A, m, r);

    vector<int> tmp;
    tmp.reserve(r-l);
    int i = l, j = m;
    while (i < m || j < r) {
        if (j == r || (i < m && A[i] <= A[j])) {
            tmp.push_back(A[i++]);
        } else {
            tmp.push_back(A[j++]);
            inv += (m - i);  // every A[i..m-1] > A[j-1]
        }
    }
    for (int k = 0; k < (int)tmp.size(); ++k)
        A[l + k] = tmp[k];

    return inv;
}

long long count_inversions(vector<int> A) {
    return merge_count(A, 0, A.size());
}

void solve() {
  int n;
  cin>>n;
  vector<int> v(n);
  for (int i=0;i<n;i++) cin>>v[i];
  vector<int> pos(n+1);
  for (int i=0;i<n;i++) {
    int a;
    cin>>a;
    pos[a]=i;
  }
  vector<int> perm(n);
  for (int i=0;i<n;i++) perm[i]=pos[v[i]];
  ll inv=count_inversions(perm);
  // because 3 flip is an even permutation, check if overall is even
  cout<<((inv%2==0)?"Possible":"Impossible");
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
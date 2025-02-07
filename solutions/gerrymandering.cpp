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
#include <iomanip>
#include <ios>
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

void solve() {
  int p,d;
  cin >> p >> d;
  vector<vector<int>> votes(d, vector<int>(2, 0));
  for (int i = 0; i < p; i++) {
    int dist,a,b;
    cin >> dist >> a >> b;
    // std::cout << votes[dist-1][0] << " " << votes[dist-1][1] << " ";
    votes[dist-1][0] += a;
    votes[dist-1][1] += b;
    // std::cout << a << " " << b << " ";
    // std::cout << votes[dist-1][0] << " " << votes[dist-1][1] << " ";
  }
  int wastea = 0, wasteb = 0, total = 0;
  for (int i = 0; i < d; i++) {
    char winner;
    int t = votes[i][0]+votes[i][1];
    int curra, currb;
    // std::cout << votes[i][0] << " " << votes[i][1];
    if (votes[i][0] > votes[i][1]) {
      winner = 'A';
      curra = votes[i][0]-(t / 2 + 1);
      currb = votes[i][1];
    } else {
      winner = 'B';
      curra = votes[i][0];
      currb = votes[i][1]-(t / 2 + 1);
    }
    cout << winner << " " << curra << " " << currb << "\n";
    total += t;
    wastea += curra;
    wasteb += currb;
  }
  double e = abs(wastea - wasteb) / static_cast<double>(total);
  cout << setprecision(16) << e;
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
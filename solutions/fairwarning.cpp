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

class BigInt {
public:
    // s holds the digits (without any sign) in normal order (most-significant digit first)
    // negative is true if the number is negative.
    string s;
    bool negative;

    // Default constructor: zero.
    BigInt() : s("0"), negative(false) {}

    // Construct from string (which may begin with '-' for negative numbers)
    BigInt(const string &str) {
        int pos = 0;
        negative = false;
        if(str[0] == '-') { 
            negative = true;
            pos++;
        }
        // Skip any leading zeros.
        while(pos < str.size() && str[pos] == '0')
            pos++;
        if(pos == str.size()){
            s = "0";
            negative = false;
        } else {
            s = str.substr(pos);
        }
    }

    // Return the string representation (with a '-' if negative and not zero).
    string toString() const {
        return (negative && s != "0" ? "-" : "") + s;
    }

    // Compare absolute values.
    // Returns -1 if |this| < |other|, 0 if equal, and 1 if greater.
    int compare_abs(const BigInt &other) const {
        if(s.size() < other.s.size()) return -1;
        if(s.size() > other.s.size()) return 1;
        if(s == other.s) return 0;
        return (s < other.s) ? -1 : 1;
    }

    // Full comparison (taking sign into account).
    int compare(const BigInt &other) const {
        if(negative != other.negative)
            return negative ? -1 : 1;
        if(!negative)
            return compare_abs(other);
        else
            return -compare_abs(other); // if both negative, order is reversed.
    }

    bool operator<(const BigInt &other) const {
        return compare(other) < 0;
    }

    bool operator==(const BigInt &other) const {
        return negative == other.negative && s == other.s;
    }

    // Helper: add two non-negative numbers given as strings.
    static string add_str(const string &a, const string &b) {
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        string result;
        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
            carry = sum / 10;
            result.push_back('0' + (sum % 10));
        }
        reverse(result.begin(), result.end());
        return result;
    }

    // Helper: subtract two non-negative numbers given as strings.
    // Assumes a >= b.
    static string sub_str(const string &a, const string &b) {
        int i = a.size()-1, j = b.size()-1, carry = 0;
        string result;
        while(i >= 0) {
            int diff = (a[i] - '0') - carry;
            if(j >= 0) diff -= (b[j] - '0');
            if(diff < 0) { diff += 10; carry = 1; } else { carry = 0; }
            result.push_back('0' + diff);
            i--; j--;
        }
        reverse(result.begin(), result.end());
        // Remove leading zeros.
        int pos = 0;
        while(pos < result.size()-1 && result[pos]=='0')
            pos++;
        return result.substr(pos);
    }

    // Addition operator.
    BigInt operator+(const BigInt &other) const {
        BigInt result;
        // If the signs are the same, add the absolute values.
        if(!negative && !other.negative) {
            result.s = add_str(s, other.s);
            result.negative = false;
        } else if(negative && other.negative) {
            result.s = add_str(s, other.s);
            result.negative = true;
        } else if(!negative && other.negative) {
            // a + (-b) = a - b.
            if(compare_abs(other) >= 0) {
                result.s = sub_str(s, other.s);
                result.negative = false;
            } else {
                result.s = sub_str(other.s, s);
                result.negative = true;
            }
        } else { // negative && !other.negative, i.e., (-a) + b = b - a.
            if(compare_abs(other) > 0) {
                result.s = sub_str(s, other.s);
                result.negative = true;
            } else {
                result.s = sub_str(other.s, s);
                result.negative = false;
            }
        }
        if(result.s == "0")
            result.negative = false;
        return result;
    }

    // Subtraction operator.
    BigInt operator-(const BigInt &other) const {
        BigInt negOther = other;
        negOther.negative = !other.negative;
        return *this + negOther;
    }

    // Multiply the BigInt by an integer factor (assumes factor >= 0).
    BigInt multiply_by_int(int factor) const {
        if(factor == 0 || s == "0")
            return BigInt("0");
        int carry = 0;
        string result;
        for (int i = s.size()-1; i >= 0; i--){
            int prod = (s[i] - '0') * factor + carry;
            carry = prod / 10;
            result.push_back('0' + (prod % 10));
        }
        while(carry) {
            result.push_back('0' + (carry % 10));
            carry /= 10;
        }
        reverse(result.begin(), result.end());
        BigInt ret(result);
        ret.negative = negative; // factor is positive so sign stays the same.
        return ret;
    }

    // Multiply by 10.
    BigInt multiply_by_10() const {
        if(s == "0") return *this;
        BigInt ret;
        ret.s = s + "0";
        ret.negative = negative;
        return ret;
    }

    // Long-division algorithm (for non-negative BigInts).
    // Returns a pair {quotient, remainder}.
    // Assumes both *this and divisor are non-negative and divisor is not 0.
    pair<BigInt, BigInt> divmod(const BigInt &divisor) const {
        if(divisor.s == "0") { throw runtime_error("Division by zero"); }
        string q;
        BigInt remainder("0");
        for (char digit : s) {
            remainder = remainder.multiply_by_10();
            BigInt d(string(1, digit));
            remainder = remainder + d;
            int count = 0;
            // Subtract divisor until remainder is less than divisor.
            while(remainder.compare(divisor) >= 0) {
                remainder = remainder - divisor;
                count++;
            }
            q.push_back('0' + count);
        }
        // Remove any leading zeros from the quotient.
        int pos = 0;
        while(pos < q.size()-1 && q[pos]=='0')
            pos++;
        BigInt quotient(q.substr(pos));
        return {quotient, remainder};
    }

    // Division operator (assumes non-negative; full sign support could be added if needed).
    BigInt operator/(const BigInt &other) const {
        return divmod(other).first;
    }

    // Modulo operator.
    BigInt operator%(const BigInt &other) const {
        return divmod(other).second;
    }

    // Return the absolute value.
    BigInt abs() const {
        BigInt ret = *this;
        ret.negative = false;
        return ret;
    }
};

BigInt gcd(BigInt a, BigInt b) {
    return b.toString() == "0" ? a : gcd(b, a % b);
}

void solve() {
  int tc;
  cin>>tc;
  for (int ii=1;ii<=tc;ii++) {
    int n;
    cin>>n;
    vector<BigInt> v(n);
    BigInt maxx("0");
    for (int i=0;i<n;i++) {
      string first;
      cin>>first;
      BigInt t(first);
      v[i]=t;
      maxx=max(maxx,t);
    }
    for (int i=0;i<n;i++) {
      v[i]=maxx-v[i];
    }
    BigInt g=v[0];
    for (int i=1;i<n;i++) {
      g=gcd(g,v[i]);
    }
    if ((maxx%g).toString()=="0") cout<<"Case #"<<ii<<": "<<0<<"\n";
    else cout<<"Case #"<<ii<<": "<<(g-maxx%g).toString()<<"\n";
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
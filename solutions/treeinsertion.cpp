#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

// Definition of the BST node.
struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// BST insertion: values less than the current node go left, others go right.
void insert(Node*& root, int x) {
    if (!root) {
        root = new Node(x);
        return;
    }
    if (x < root->val)
        insert(root->left, x);
    else
        insert(root->right, x);
}

// Free the BST memory.
void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

/* 
   Big integer functions:
   We represent big integers as strings (with no extra leading zeros) in base 10.
*/

// Multiply a big integer (as string) by an int.
string multiplyInt(const string &num, int b) {
    int carry = 0;
    string result = num;
    for (int i = result.size()-1; i >= 0; i--) {
        int d = result[i] - '0';
        long long prod = (long long)d * b + carry;
        result[i] = char((prod % 10) + '0');
        carry = prod / 10;
    }
    while(carry > 0) {
        char digit = char((carry % 10) + '0');
        result.insert(result.begin(), digit);
        carry /= 10;
    }
    return result;
}

// Divide a big integer (as string) by an int. We assume the division is exact.
string divideInt(const string &num, int b) {
    string result;
    int remainder = 0;
    for (char c: num) {
        remainder = remainder * 10 + (c - '0');
        int q = remainder / b;
        remainder %= b;
        result.push_back(q + '0');
    }
    // Remove any leading zeros.
    size_t pos = result.find_first_not_of('0');
    if (pos == string::npos) return "0";
    return result.substr(pos);
}

// Multiply two big integers represented as strings.
string multiplyBig(const string &a, const string &b) {
    int n = a.size(), m = b.size();
    vector<int> result(n + m, 0);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int prod = (a[i] - '0') * (b[j] - '0');
            int sum = prod + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    string res;
    for (int digit : result) {
        if (!(res.empty() && digit == 0))
            res.push_back(digit + '0');
    }
    return res.empty() ? "0" : res;
}

// Compute binomial coefficient C(n, k) = n! / (k!(n-k)!) as a big integer string.
string binom(int n, int k) {
    if(k > n) return "0";
    if(k > n - k) k = n - k; // Use symmetry.
    string res = "1";
    for (int i = 1; i <= k; i++) {
        res = multiplyInt(res, n - k + i);
        res = divideInt(res, i);
    }
    return res;
}

/*
   Recursively compute the number of insertion orders for the BST.
   The function returns a pair: 
     - first: the number of nodes in the subtree
     - second: the big integer (as a string) for the count.
*/
pair<int, string> solve(Node* root) {
    if (!root) return {0, "1"};
    auto leftRes = solve(root->left);
    auto rightRes = solve(root->right);
    int leftSize = leftRes.first;
    int rightSize = rightRes.first;
    int total = leftSize + rightSize;
    string waysBinom = binom(total, leftSize);
    // f(T) = binom(L+R, L) * f(left) * f(right)
    string ways = multiplyBig(waysBinom, leftRes.second);
    ways = multiplyBig(ways, rightRes.second);
    return {total + 1, ways};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(true) {
        int n;
        cin >> n;
        if(n == 0) break;
        Node* root = nullptr;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            insert(root, x);
        }
        auto result = solve(root);
        cout << result.second << "\n";
        deleteTree(root);
    }
    return 0;
}
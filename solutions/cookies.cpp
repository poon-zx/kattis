#include <iostream>
using namespace std;

int cookies(int N, int* A) {
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += (long long)A[i];
    }
    return sum;
}
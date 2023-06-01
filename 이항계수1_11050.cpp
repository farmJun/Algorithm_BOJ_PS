#include "iostream"

using namespace std;

int N, K;

int combination(int n, int k) {
    if (k == 0 || n == k) {
        return 1;
    }

    return combination(n - 1, k - 1) + combination(n - 1, k);
}

int main() {
    cin >> N >> K;
    cout << combination(N, K);
}
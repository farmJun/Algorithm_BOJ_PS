#include "iostream"

using namespace std;

long long dp[1001][1001];
int t, n, k;

int combination(int n, int k) {
    if (k == 0 || n == k) {
        return dp[n][k] = 1;
    }

    if (dp[n][k] != 0) {
        return dp[n][k];
    }

    return dp[n][k] = combination(n - 1, k - 1) + combination(n - 1, k);
}


int main() {
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        cin >> k >> n;

        cout <<  combination(n, k) << "\n";
    }
}
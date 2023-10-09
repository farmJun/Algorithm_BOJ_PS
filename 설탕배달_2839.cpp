#include "iostream"

using namespace std;

int dp[5001];

int main() {

    fill(dp, dp + 5001, 10000);

    int n;
    cin >> n;

    dp[3] = 1;
    dp[5] = 1;

    for (int i = 6; i <= n; i++) {
        dp[i] = min(dp[i - 3], dp[i - 5]) + 1;

    }

    if (dp[n] >= 5001) {
        cout << -1;
    } else {
        cout << dp[n];
    }
}

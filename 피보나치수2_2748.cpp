#include "iostream"

using namespace std;


long long dp[91];
int n;

int main() {
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 0; i < n; i++) {
        dp[i + 2] = dp[i] + dp[i + 1];
    }


    cout << dp[n];
}
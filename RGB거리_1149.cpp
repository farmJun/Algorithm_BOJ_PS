#include "iostream"

using namespace std;

int table[1001][3];
int dp[1001][3];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> table[i][j];
        }
    }

    dp[0][0] = table[0][0];
    dp[0][1] = table[0][1];
    dp[0][2] = table[0][2];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0) {
                dp[i][j] = min(dp[i - 1][1], dp[i - 1][2]) + table[i][j];
                continue;
            }

            if (j == 1) {
                dp[i][j] = min(dp[i - 1][0], dp[i - 1][2]) + table[i][j];
                continue;
            }

            if (j == 2) {
                dp[i][j] = min(dp[i - 1][0], dp[i - 1][1]) + table[i][j];
            }
        }
    }

    int ans = 987654321;
    for (int i = 0; i < 3; i++) {
        ans = min(ans, dp[n - 1][i]);
    }

    cout << ans;


}
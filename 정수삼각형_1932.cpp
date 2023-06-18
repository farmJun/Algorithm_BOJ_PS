#include "iostream"

using namespace std;


long long dp[501][501];
int map[501][501];

int n;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> map[i][j];
        }
    }

    long long maxV = 0;

    dp[0][0] = map[0][0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {

            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + map[i][j];
            } else if (i == j) {
                dp[i][j] = dp[i - 1][j - 1] + map[i][j];
            } else {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + map[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        maxV = max(maxV, dp[n - 1][i]);
    }
    cout << maxV;
}

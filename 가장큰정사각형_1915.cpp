#include "iostream"

using namespace std;

int map[1001][1001];
int dp[1001][1001];
//dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1

int n, m;

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string line;
        cin >> line;

        for (int j = 0; j < m; j++) {
            map[i][j + 1] = (int) line[j] - '0';
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] == 1) {
                dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans * ans;
}

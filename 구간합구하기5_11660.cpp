#include "iostream"

using namespace std;

int dp[1025][1025];
int num[1025][1025];
int n, m, x, y, x2, y2;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> num[i][j];
        }
    }

    dp[0][0] = 0;


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + num[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> x >> y >> x2 >> y2;
        cout << dp[x2][y2] - dp[x - 1][y2] - dp[x2][y - 1] + dp[x - 1][y - 1] << '\n';
    }
}
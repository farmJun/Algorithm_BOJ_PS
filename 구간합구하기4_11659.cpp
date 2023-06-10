#include "iostream"

using namespace std;

int dp[100001];
int num[100001];
int n, m, a, b;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + num[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << dp[b] - dp[a - 1] << '\n';
    }
}
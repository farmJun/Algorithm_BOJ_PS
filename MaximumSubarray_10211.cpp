#include "iostream"
#include "climits"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n + 1];
        int dp[n + 1];
        dp[0] = 0;
        int maxNum = INT_MIN;

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        for (int i = 1; i <= n; i++) {
            dp[i] = max(arr[i] + dp[i - 1], arr[i]);
            maxNum = max(maxNum, dp[i]);
        }

        cout << maxNum << "\n";
    }
}
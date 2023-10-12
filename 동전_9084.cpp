#include "iostream"

using namespace std;

int dp[10001];

int main(){

    int t;
    cin >> t;

    for(int i=0; i<t;i++){
        fill(dp, dp+10001, 0);

        int n, m;
        cin >> n;

        int coin[n];

        for(int j=0;j<n;j++){
            cin >> coin[j];
        }
        cin >> m;

        dp[0] = 1;

        for (int j = 0; j < n; j++) {
            for (int k= coin[j]; k <= m; k++) {
                dp[k] += dp[k - coin[j]];
            }
        }

        cout << dp[m] << "\n";
    }
}
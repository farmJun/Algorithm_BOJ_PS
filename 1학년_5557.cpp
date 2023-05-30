#include "iostream"

using namespace std;

int numbers[101];
long long dp[101][21];
int N;


int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> numbers[i];
    }

    dp[1][numbers[1]] = 1L;

    for (int i = 2; i < N; i++) {
        for (int j = 0; j <= 20; j++) {

            if (j - numbers[i] >= 0) {
                dp[i][j - numbers[i]] += dp[i - 1][j];
            }

            if (j + numbers[i] <= 20) {
                dp[i][j + numbers[i]] += dp[i - 1][j];
            }
        }
    }

    cout << dp[N - 1][numbers[N]];

}
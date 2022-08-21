#include "iostream"

using namespace std;


int arr[1001];
int dp[1001];

int main() {

    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        int standard = 0;

        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                standard = max(dp[j], standard);
            }
        }
        dp[i] = standard + 1;
        cnt = max(cnt, dp[i]);
    }

    cout << cnt;


}
#include <iostream>

using namespace std;

int score[101], play[101], ans[101];

int main() {
    int m, n;

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> score[i];
    }

    for (int i = 1; i <= m; i++) {
        int target = score[i];

        int cnt = 0;

        for (int j = 1; j <= n; j++) {
            cin >> play[j];
        }
        for (int j = 1; j <= n; j++) {
            if (target == play[j]) {
                ans[j]++;
            } else {
                cnt++;
            }
        }
        ans[score[i]] += cnt;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
}

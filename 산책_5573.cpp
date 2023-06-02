#include "iostream"

using namespace std;


int H, W, N;
int dp[1111][1111];
int map[1111][1111];

void solve(int x, int y) {
    if (x > H || y > W) {
        cout << x << " " << y;
        return;
    }

    if (map[x][y] == 1) {
        solve(x, y + 1);
    } else {
        solve(x + 1, y);
    }
}

int main() {

    cin >> H >> W >> N;

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> map[i][j];
        }
    }

    dp[1][1] = N - 1;

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {

            int value = dp[i][j];

            if (map[i][j] == 1) {
                dp[i][j + 1] += value / 2 + value % 2;
                dp[i + 1][j] += value / 2;
            } else {
                dp[i][j + 1] += value / 2;
                dp[i + 1][j] += value / 2 + value % 2;
            }
        }
    }


    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            map[i][j] = (map[i][j] + dp[i][j] % 2) % 2;
        }
    }
    solve(1, 1);

}
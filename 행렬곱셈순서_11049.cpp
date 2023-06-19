#include <iostream>
#include <vector>

using namespace std;

int n;

int matrix[501][2]; // 행렬의 최소 곱셈 연산 수를 저장하는 배열
int dp[501][501]; // 행렬의 차원을 저장하는 배열
vector<pair<int, int>> mat;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    mat.push_back({0, 0});
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        mat.push_back({a, b});
        //matrix[i][0] = a;
        //matrix[i][1] = b;
        //cin >> matrix[i][0];
        //cin >> matrix[i][1];
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {

            int j = i + l - 1;
            dp[i][j] = 123456789;
            for (int k = i; k <= j - 1; k++) {
                //int q = dp[i][k] + dp[k + 1][j] + matrix[i][0] * matrix[k][1] * matrix[j][1];
                int q = dp[i][k] + dp[k + 1][j] + mat[i].first * mat[k].second * mat[j].second;

                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }


    cout << dp[1][n];

}

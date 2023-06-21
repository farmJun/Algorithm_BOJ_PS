#include "iostream"

using namespace std;


int n;
int map[100001][3];
int dpMax[100001][3];
int dpMin[100001][3];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> map[i][j];
        }
    }

    dpMin[0][0] = map[0][0];
    dpMin[0][1] = map[0][1];
    dpMin[0][2] = map[0][2];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0) {
                dpMin[i][j] = min(dpMin[i - 1][j], dpMin[i - 1][j + 1]) + map[i][j];
            } else if (j == 1) {
                dpMin[i][j] = min(dpMin[i - 1][j - 1], min(dpMin[i - 1][j], dpMin[i - 1][j + 1])) + map[i][j];
            } else {
                dpMin[i][j] = min(dpMin[i - 1][j], dpMin[i - 1][j - 1]) + map[i][j];
            }
        }
    }

    int minV = min(dpMin[n - 1][0], min(dpMin[n - 1][1], dpMin[n - 1][2]));

    dpMax[0][0] = map[0][0];
    dpMax[0][1] = map[0][1];
    dpMax[0][2] = map[0][2];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0) {
                dpMax[i][j] = max(dpMax[i - 1][j], dpMax[i - 1][j + 1]) + map[i][j];
            } else if (j == 1) {
                dpMax[i][j] = max(dpMax[i - 1][j - 1], max(dpMax[i - 1][j], dpMax[i - 1][j + 1])) + map[i][j];
            } else {
                dpMax[i][j] = max(dpMax[i - 1][j], dpMax[i - 1][j - 1]) + map[i][j];
            }
        }
    }

    int maxV = max(dpMax[n - 1][0], max(dpMax[n - 1][1], dpMax[n - 1][2]));


    cout << maxV << ' ' << minV;
}
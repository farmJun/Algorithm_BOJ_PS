#include "iostream"

using namespace std;


int n, a, b, c, tmp1, tmp2;
int dpMax[3];
int dpMin[3];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;

        if (i == 0) {
            dpMin[0] = a;
            dpMin[1] = b;
            dpMin[2] = c;

            dpMax[0] = a;
            dpMax[1] = b;
            dpMax[2] = c;
        } else {
            tmp1 = dpMin[0];
            tmp2 = dpMin[2];

            dpMin[0] = min(dpMin[0], dpMin[1]) + a;
            dpMin[2] = min(dpMin[1], dpMin[2]) + c;
            dpMin[1] = min(dpMin[1], min(tmp1, tmp2)) + b;

            tmp1 = dpMax[0];
            tmp2 = dpMax[2];

            dpMax[0] = max(dpMax[0], dpMax[1]) + a;
            dpMax[2] = max(dpMax[1], dpMax[2]) + c;
            dpMax[1] = max(dpMax[1], max(tmp1, tmp2)) + b;
        }
    }

    int minV = min(dpMin[0], min(dpMin[1], dpMin[2]));
    int maxV = max(dpMax[0], max(dpMax[1], dpMax[2]));
    cout << maxV << ' ' << minV;

}
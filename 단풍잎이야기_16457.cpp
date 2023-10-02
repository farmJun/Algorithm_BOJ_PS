#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int n, m, k;
int quest[101][10];

int maxNum = 0;

void combination(vector<int> arr, vector<int> comb, int r, int index, int depth) {
    if (r == 0) {
        int cnt = 0;

        for (int i = 0; i < m; i++) {
            bool possible = false;

            for (int j = 0; j < k; j++) {
                std::vector<int>::iterator it = std::find(comb.begin(), comb.end(), quest[i][j]);

                if (it != comb.end()) {
                    possible = true;
                } else {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                cnt++;
            }
        }
        if (cnt > maxNum) {
            maxNum = cnt;
        }
        return;
    } else if (depth == arr.size()) {
        return;
    } else {
        comb[index] = arr[depth];
        combination(arr, comb, r - 1, index + 1, depth + 1);
        combination(arr, comb, r, index, depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> quest[i][j];
        }
    }

    vector<int> arr;
    vector<int> comb(n);

    for (int i = 1; i <= 2 * n; i++) {
        arr.push_back(i);
    }

    combination(arr, comb, n, 0, 0);
    cout << maxNum;
}


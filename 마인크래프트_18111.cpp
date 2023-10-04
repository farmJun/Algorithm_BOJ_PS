#include "iostream"
#include "climits"

using namespace std;

int block[500][500];

int main() {
    int n, m, b;

    cin >> n >> m >> b;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> block[i][j];
        }
    }

    int finalTime = INT_MAX;
    int finalH = 0;

    for (int h = 0; h <= 256; h++) {
        int blockToPlace = 0;
        int blockToRemove = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (h > block[i][j]) {
                    blockToPlace += h - block[i][j];
                } else {
                    blockToRemove += abs(h - block[i][j]);
                }
            }
        }

        if (b + blockToRemove >= blockToPlace) {

            int time = blockToPlace + blockToRemove * 2;

            if (time < finalTime) {
                finalTime = time;
                finalH = h;
            }

            if (time == finalTime) {
                if (h > finalH) {
                    finalH = h;
                }
            }
        }
    }
    cout << finalTime << " " << finalH;
}
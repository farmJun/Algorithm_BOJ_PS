#include "iostream"

using namespace std;

int triangle[501][501];

int main() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }

    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            int big = max(triangle[i][j],triangle[i][j+1]);
            triangle[i-1][j]+= big;
        }
    }

    cout << triangle[1][1];


}
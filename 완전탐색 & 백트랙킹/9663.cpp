#include "iostream"

using namespace std;

int n;
int arr[16];
int cnt = 0;

bool isPossible(int y, int x) {
    for (int i = 1; i < y; i++) {
        if (arr[i] == x || abs(arr[i] - x) == abs(y - i)) {
            return false;
        }
    }
    return true;
}

void nQueen(int y, int x) {

    if(y==n+1){
        cnt++;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (isPossible(y, i)) {
            arr[y] = i;
            nQueen(y + 1, x);
        }
    }
}

int main() {
    cin >> n;
    nQueen(1, 1);
    cout << cnt;
}
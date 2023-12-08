#include "iostream"
#include "cmath"

using namespace std;

bool arr[123456 * 2 + 1];

int main() {

    for (int i = 2; i <= 123456 * 2; i++) {
        arr[i] = true;
    }

    for (int i = 2; i * i <= 123456 * 2; i++) {
        if (!arr[i]) {
            continue;
        }

        for (int j = i * i; j <= 123456 * 2; j += i) {
            arr[j] = false;
        }
    }

    int n;

    while (true) {
        cin >> n;
        int cnt = 0;
        if (n == 0) {
            break;
        }
        for (int i = n + 1; i <= 2 * n; i++) {
            if (arr[i]) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}
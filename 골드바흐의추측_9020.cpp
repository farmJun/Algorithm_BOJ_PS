#include "iostream"
#include "cmath"

using namespace std;

bool arr[10000 + 1];

int main() {

    for (int i = 2; i <= 10000; i++) {
        arr[i] = true;
    }

    for (int i = 2; i * i <= 10000; i++) {
        if (!arr[i]) {
            continue;
        }

        for (int j = i * i; j <= 10000; j += i) {
            arr[j] = false;
        }
    }


    int n;
    cin >> n;;
    while (n--) {
        int a;
        cin >> a;

        for (int i = a / 2; i >= 2; i--) {
            if (arr[i] && arr[a - i]) {
                cout << i << " " << a - i << "\n";
                break;
            }
        }
    }

}
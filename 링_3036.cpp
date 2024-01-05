#include "iostream"

using namespace std;

int gcd(int a, int b) {
    int n;

    while (b != 0) {
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}


int main() {

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++) {
        int div = gcd(arr[0], arr[i]);
        cout << arr[0] / div << "/" << arr[i] / div << "\n";
    }
}
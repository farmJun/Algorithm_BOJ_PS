#include "iostream"

using namespace std;

pair<int, int> arr[41];

pair<int, int> fibonacci(int n) {
    if (n == 0) {
        return arr[0];
    } else if (n == 1) {
        return arr[1];
    } else {

        if (arr[n - 1].first == 0 && arr[n - 1].second == 0) {
            arr[n - 1] = fibonacci(n - 1);
        }

        if (arr[n - 2].first == 0 && arr[n - 2].second == 0) {
            arr[n - 2] = fibonacci(n - 2);
        }

        return arr[n] = {arr[n - 1].first + arr[n - 2].first, arr[n - 1].second + arr[n - 2].second};
    }
}

int main() {
    arr[0] = {1, 0};
    arr[1] = {0, 1};
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        pair<int, int> p = fibonacci(n);
        cout << p.first << " " << p.second << "\n";
    }
}
#include "iostream"

using namespace std;

long X, Y, Z;

int main() {

    cin >> X >> Y;
    Z = 100 * Y / X;

    if (Z >= 99) {
        cout << -1;
        return 0;
    }

    int start = 1;
    int end = X;

    while (true) {
        int mid = (start + end) / 2;
        int winRate = 100 * (Y + mid) / (X + mid);

        if (winRate == Z) {
            start = mid + 1;
        } else if (winRate > Z) {
            end = mid;
        }

        if (start == end) {
            break;
        }
    }

    cout << end;
}
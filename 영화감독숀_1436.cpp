#include "iostream"

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0, ans = 0;
    while (cnt != n) {
        ++ans;
        int temp = ans;
        while (temp != 0) {
            if (temp % 1000 == 666) {
                ++cnt;
                break;
            } else {
                temp /= 10;
            }
        }
    }
    cout << ans;

}
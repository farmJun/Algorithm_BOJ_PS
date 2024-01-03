#include<iostream>

using namespace std;

int a, b, total, num;
int cnt[100];

int main() {
    cin >> a >> b;

    for (int i = 0; i <= 100; i++) {

        if (a <= i * i && b >= i * i) {
            total += i * i;
            cnt[num] = i * i;
            num++;
        }

    }

    if (num == 0) {
        cout << "-1";
    } else {
        cout << total << endl;
        cout << cnt[0];
    }


}
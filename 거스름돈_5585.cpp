#include <iostream>

using namespace std;

int coin[] = {500, 100, 50, 10, 5, 1};

int main() {
    int money;
    cin >> money;
    int realMoney = 1000 - money;
    int cnt = 0;

    for (int i = 0; i <= 5; i++) {
        cnt += realMoney / coin[i];
        realMoney %= coin[i];
    }

    cout << cnt;


}
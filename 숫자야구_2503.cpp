#include "iostream"

using namespace std;

bool num[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fill(num, num + 1000, true);

    string ask;
    int n, strike, ball;
    cin >> n;

    for (int i = 100; i < 1000; i++) {
        string str = to_string(i);

        if (str[0] == str[1] || str[1] == str[2] || str[2] == str[0] || str[0] - '0' == 0 || str[1] - '0' == 0 ||
            str[2] - '0' == 0) {
            num[i] = false;
        }
    }

    while (n--) {
        cin >> ask >> strike >> ball;

        for (int i = 100; i < 1000; i++) {
            int s = 0;
            int b = 0;

            if (num[i]) {
                string compare = to_string(i);


                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {

                        if (ask[j] == compare[k] && j == k) {
                            s++;
                        }

                        if (ask[j] == compare[k] && j != k) {
                            b++;
                        }
                    }
                }
                if (s != strike || b != ball) {
                    num[i] = false;
                }
            }
        }
    }

    int cnt = 0;

    for (int i = 100; i < 1000; i++) {
        if (num[i]) {
            cnt++;
        }
    }
    cout << cnt;

}
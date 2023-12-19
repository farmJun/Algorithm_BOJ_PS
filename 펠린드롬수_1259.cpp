#include <iostream>
#include <string>

using namespace std;

int main() {

    while (true) {
        int a;
        cin >> a;
        if (a == 0) {
            break;
        }

        string s = to_string(a);
        bool is = true;

        for (int i = 0; i < s.length() / 2; i++) {
            if (s[i] != s[s.length() - i - 1]) {
                is = false;
                break;
            }
        }
        if (is) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}
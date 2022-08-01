#include "iostream"
#include "map"

using namespace std;

int main() {
    int N;
    string s;
    int cnt = 0;

    cin >> N;
    map<string, bool> user;

    for (int i = 0; i < N; i++) {
        cin >> s;
        if (s == "ENTER") {
            user.erase(user.begin(), user.end());
        } else {
            if (!user[s]) {
                cnt++;
                user[s] = true;
            }
        }
    }
    cout << cnt;
}

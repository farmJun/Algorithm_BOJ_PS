#include "iostream"
#include "stack"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        stack<int> vps;
        bool possible = true;

        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '(') {
                vps.push(1);
            } else {
                if (vps.empty()) {
                    cout << "NO\n";
                    possible = false;
                    break;
                }
                vps.pop();
            }
        }

        if (possible) {
            if (vps.empty()) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}



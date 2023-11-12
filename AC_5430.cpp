#include "iostream"
#include "string"
#include "deque"
#include "sstream"
#include "algorithm"

using namespace std;

deque <string> split(string str, char Delimiter) {
    istringstream iss(str);
    string buffer;

    deque <string> result;

    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    string p, arr;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> p;
        cin >> n;
        cin >> arr;


        arr.erase(remove(arr.begin(), arr.end(), '['), arr.end());
        arr.erase(remove(arr.begin(), arr.end(), ']'), arr.end());

        deque <string> realArr = split(arr, ',');

        bool reverse = false;
        bool isPossible = true;

        for (int j = 0; j < p.size(); j++) {
            if (p[j] == 'R') {
                reverse = !reverse;
            } else if (p[j] == 'D') {
                if (realArr.empty()) {
                    cout << "error\n";
                    isPossible = false;
                    break;
                }
                if (reverse) {
                    realArr.pop_back();
                } else {
                    realArr.pop_front();
                }
            }
        }

        if (isPossible) {
            cout << "[";
        }
        if (isPossible && reverse) {
            while (!realArr.empty()) {
                cout << realArr.back();
                realArr.pop_back();
                if (!realArr.empty()) {
                    cout << ",";
                }
            }

        } else if (isPossible && !reverse) {
            while (!realArr.empty()) {
                cout << realArr.front();
                realArr.pop_front();
                if (!realArr.empty()) {
                    cout << ",";
                }
            }
        }
        if (isPossible) {
            cout << "]\n";
        }
    }
}

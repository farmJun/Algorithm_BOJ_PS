#include "iostream"
#include "queue"
#include "vector"
#include "sstream"

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<queue<string>> word(n);
    queue<string> standard;

    string s;
    getline(cin, s);

    for (int i = 0; i < n; i++) {
        getline(cin, s);
        istringstream ss(s);
        string w;

        while (getline(ss, w, ' ')) {
            word[i].push(w);
        }
    }

    string l;
    getline(cin, l);
    istringstream ss(l);
    string l2;

    while (getline(ss, l2, ' ')) {
        standard.push(l2);
    }

    bool possible = true;

    while (!standard.empty()) {
        bool nowPossible = false;

        for (int i = 0; i < n; i++) {
            if (word[i].front() == standard.front() && !word[i].empty()) {
                word[i].pop();
                standard.pop();
                nowPossible = true;
                break;
            }
        }
        if (!nowPossible) {
            possible = false;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!word[i].empty()) {
            cout << "Impossible";
            return 0;
        }
    }

    if (possible) {
        cout << "Possible";
    } else {
        cout << "Impossible";
    }

}
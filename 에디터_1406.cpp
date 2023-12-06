#include "iostream"
#include "deque"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    deque<char> cursorLeft;
    deque<char> cursorRight;
    string input, order;
    int M;

    cin >> input >> M;

    for (int i = 0; i < input.length(); i++) {
        cursorLeft.push_back(input[i]);
    }

    for (int i = 0; i < M; i++) {
        cin >> order;
        if (order == "L") {
            if (!cursorLeft.empty()) {
                cursorRight.push_front(cursorLeft.back());
                cursorLeft.pop_back();
            }
        } else if (order == "D") {
            if (!cursorRight.empty()) {
                cursorLeft.push_back(cursorRight.front());
                cursorRight.pop_front();
            }
        } else if (order == "B") {
            if (!cursorLeft.empty()) {
                cursorLeft.pop_back();
            }
        } else if (order == "P") {
            char add;
            cin >> add;
            cursorLeft.push_back(add);
        }
    }

    while (!cursorLeft.empty()) {
        cout << cursorLeft.front();
        cursorLeft.pop_front();
    }
    while (!cursorRight.empty()) {
        cout << cursorRight.front();
        cursorRight.pop_front();
    }
}
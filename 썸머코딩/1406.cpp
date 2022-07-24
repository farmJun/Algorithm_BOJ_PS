#include "iostream"
#include "stack"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<char> cursorLeft;
    stack<char> cursorRight;
    string input, order;
    int M;

    cin >> input >> M;

    for (int i = 0; i < input.length(); i++) {
        cursorLeft.push(input[i]);
    }

    for (int i = 0; i < M; i++) {
        cin >> order;
        if (order == "L") {
            if (!cursorLeft.empty()) {
                cursorRight.push(cursorLeft.top());
                cursorLeft.pop();
            }
        } else if (order == "D") {
            if (!cursorRight.empty()) {
                cursorLeft.push(cursorRight.top());
                cursorRight.pop();
            }
        } else if (order == "B") {
            if (!cursorLeft.empty()) {
                cursorLeft.pop();
            }
        } else if (order == "P") {
            char add;
            cin >> add;
            cursorLeft.push(add);
        }
    }

    while (!cursorLeft.empty()) {
        cursorRight.push(cursorLeft.top());
        cursorLeft.pop();
    }

    while (!cursorRight.empty()) {
        cout << cursorRight.top();
        cursorRight.pop();
    }
}
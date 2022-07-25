#include "iostream"
#include "stack"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int cnt = 0;
    stack<char> stick;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            stick.push(s[i]);
        } else if (s[i] == ')' && s[i - 1] == '(') {
            stick.pop();
            cnt += stick.size();
        } else if (s[i] == ')') {
            stick.pop();
            cnt++;
        }
    }
    cout << cnt;
}

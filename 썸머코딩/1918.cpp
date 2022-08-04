#include "iostream"
#include "stack"

using namespace std;

int main() {

    stack<char> st;
    string data;
    cin >> data;

    for (int i = 0; i < data.size(); i++) {
        if (data[i] >= 'A' && data[i] <= 'Z') {
            cout << data[i];
        } else {
            if (data[i] == '(') {
                st.push(data[i]);
            } else if (data[i] == '*' || data[i] == '/') {
                while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                    cout << st.top();
                    st.pop();
                }
                st.push(data[i]);
            } else if (data[i] == '+' || data[i] == '-') {
                while (!st.empty() && st.top() != '(') {
                    cout << st.top();
                    st.pop();
                }
                st.push(data[i]);
            } else if (data[i] == ')') {
                while (!st.empty() && st.top() != '(') {
                    cout << st.top();
                    st.pop();
                }
                st.pop();
            }
        }
    }

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}
#include<iostream>
#include<stack>

using namespace std;

string input;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> input;
    stack<int> st;
    st.push(1);

    int ans = 0;

    for (int i = 0; i < str.length(); i++) {
        if (input[i + 1] == '(') {
            st.push(st.top() * (input[i++] - '0'));
        } else if (input[i] == ')') {
            st.pop();
        } else {
            ans += st.top();
        }
    }
    cout << ans;
}
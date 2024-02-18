#include "iostream"
#include "stack"

using namespace std;
int n, ans;
string input;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> input;
        stack<char> st;
        for (char c: input) {
            if (!st.empty() && st.top() == c) {
                st.pop();
            } else{
                st.push(c);
            }
        }

        if (st.empty()) {
            ans++;
        }
    }
    cout << ans;
}
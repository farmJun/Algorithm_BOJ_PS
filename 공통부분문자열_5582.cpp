#include "iostream"
#include "stack"

using namespace std;


int dp[4001][4001];
string s, t;
stack<char> st;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> s >> t;
    int maxV = 0;

    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < t.length(); j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }


    int len1 = s.length() - 1;
    int len2 = t.length() - 1;

    int ans = dp[len1 + 1][len2 + 1];

    while (len1 != -1 && len2 != -1) {
        if (s[len1] == t[len2]) {
            st.push(s[len1]);
            len1--;
            len2--;
        } else if (dp[len1 + 1][len2 + 1] == dp[len1][len2 + 1]) {
            len1--;
        } else if (dp[len1 + 1][len2 + 1] == dp[len1 + 1][len2]) {
            len2--;
        }
    }

    cout << ans << '\n';

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }

}
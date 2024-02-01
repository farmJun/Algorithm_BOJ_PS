#include "iostream"
using namespace std;
string s;
int ans[26];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    for (int i = 0; i < s.length(); i++) ans[s[i] - 'a']++;
    for (int i = 0; i < 26; i++) cout << ans[i] << ' ';
}
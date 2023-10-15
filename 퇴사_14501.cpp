#include "iostream"
#include "vector"

using namespace std;

int dp[1001];

int main() {

    vector<pair<int, int>> sangDam;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        sangDam.push_back({a, b});
    }

    int maxNum = 0;

    for (int i = n; i >= 0; i--) {
        if (i + sangDam[i].first <= n) {
            sangDam[i].second = max(sangDam[i + 1].second, sangDam[i].second + sangDam[i + sangDam[i].first].second);
            maxNum = max(maxNum, sangDam[i].second);
        } else {
            sangDam[i].second = sangDam[i + 1].second;
        }
    }

    cout << maxNum;
}
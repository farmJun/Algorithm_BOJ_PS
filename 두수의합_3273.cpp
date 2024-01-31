#include "iostream"
#include "algorithm"

using namespace std;
int arr[1000001], ans[1000001], n, x;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n, greater<int>());
    cin >> x;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (x - arr[i] < 0) continue;
        if (ans[x - arr[i]] == 1) cnt++;
        ans[arr[i]] = 1;
    }
    cout << cnt;
}
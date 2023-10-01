#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    int arr[n + 1];

    for (int i = 0; i < n; i++) {
        cin >> arr[i + 1];
    }

    vector<int> kit;

    for (int i = 1; i <= n; i++) {
        kit.push_back(i);
    }

    int cnt = 0;
    do {
        int total = 500;
        for (auto iter = kit.begin(); iter != kit.end(); iter++) {
            total += arr[*iter];
            total -= k;
            if(total < 500){
                break;
            }
        }
        if (total >= 500) {
            cnt++;
        }
    } while (next_permutation(kit.begin(), kit.end()));

    cout << cnt;
}
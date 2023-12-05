#include "iostream"
#include "stack"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack <pair<int, int>> tower;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        bool possible = false;

        while (!tower.empty()) {
            if (tower.top().first > a) {
                cout << tower.top().second << " ";
                possible = true;
                break;
            }
            tower.pop();
        }

        if (!possible) {
            cout << 0 << " ";
        }
        tower.push(pair<int, int>(a, i + 1));
    }
}
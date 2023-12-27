#include "iostream"
#include "queue"

using namespace std;

int main() {

    int N, H, T;
    cin >> N >> H >> T;
    priority_queue<int, vector<int>, less<int>> giant;

    for (int i = 0; i < N; i++) {
        int h;
        cin >> h;
        giant.push(h);
    }

    for (int i = 0; i < T; i++) {
        int h = giant.top();

        if (h < H) {
            cout << "YES\n";
            cout << i << "\n";
            return 0;
        } else if (h > 1) {
            giant.pop();
            giant.push(h / 2);
        }
    }

    if (giant.top() >= H) {
        cout << "NO\n" << giant.top();
    } else {
        cout << "YES\n" << T << "\n";
    }

}
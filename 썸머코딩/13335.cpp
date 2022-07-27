#include "iostream"
#include "queue"
#include "deque"

using namespace std;

int main() {

    queue<int> truck;
    deque<pair<int, int>> bridge;
    int n, w, l;
    cin >> n >> w >> l;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        truck.push(a);
    }

    int cnt = 0;
    int total = 0;

    while (true) {
        if (truck.empty() && bridge.empty()) {
            cout << cnt + 1;
            break;
        } else {
            cnt++;
        }

        if (!truck.empty() && total + truck.front() <= l) {
            bridge.push_back(pair<int, int>(truck.front(), 0));
            total += truck.front();
            truck.pop();
        }

        for (int i = 0; i < bridge.size(); i++) {
            bridge[i].second++;
        }

        if (bridge.front().second == w) {
            total -= bridge.front().first;
            bridge.pop_front();
        }
    }
}

#include "iostream"
#include "deque"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    deque<int> card;

    for (int i = 1; i <= n; i++) {
        card.push_back(i);
    }

    while (card.size() != 1) {
        card.pop_front();
        card.push_back(card.front());
        card.pop_front();
    }
    cout << card.front();

}
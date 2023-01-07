#include "iostream"
#include "set"

using namespace std;

set<int> answer;
int cards[11];
bool visited[11];

int n, k;


void bfs(int number, int count) {
    if (count == k) {
        answer.insert(number);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            continue;
        }

        visited[i] = true;
        int temp = cards[i] >= 10 ? 100 : 10;
        bfs(number * temp + cards[i], count + 1);
        visited[i] = false;
    }

}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    bfs(0, 0);
    cout << answer.size();

}
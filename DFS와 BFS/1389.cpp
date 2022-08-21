#include "iostream"
#include "queue"
#include "vector"
#include "climits"

using namespace std;

vector<int> graph[5001];
bool visited[101];

int bfs(int start, int end) {
    queue<pair<int, int>> q;

    q.push({start, 0});

    while (!q.empty()) {
        int front = q.front().first;
        int count = q.front().second;
        q.pop();

        if (front == end) {
            return count;
        }
        if (visited[front]) {
            continue;
        }

        visited[front] = true;

        for (auto i: graph[front]) {
            if (!visited[i]) {
                q.push({i, count + 1});
            }
        }
    }
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int minNum = INT_MAX;
    int minIndex = 0;

    for (int i = 1; i <= n; i++) {
        int total = 0;

        for (int j = 1; j <= n; j++) {

            if (i == j) {
                continue;
            }

            total += bfs(i, j);

            for (int k = 0; k < 102; k++) {
                visited[k] = false;
            }
        }
        if (total < minNum) {
            minNum = total;
            minIndex = i;
        }
    }
    cout << minIndex << "\n";
}

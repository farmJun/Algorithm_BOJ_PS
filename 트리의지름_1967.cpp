#include "iostream"
#include "queue"

using namespace std;

vector<pair<int, int>> graph[10001];
bool visited[10001];
int inDegree[10001];

int bfs(int start) {
    queue<pair<int, int>> q;

    q.push({start, 0});

    int number = 0;

    while (!q.empty()) {
        int front = q.front().first;
        int count = q.front().second;
        q.pop();

        number = max(number, count);

        if (visited[front]) {
            continue;
        }

        visited[front] = true;

        for (auto i: graph[front]) {
            if (!visited[i.first]) {
                q.push({i.first, count + i.second});
            }
        }
    }

    return number;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
        inDegree[a]++;
        inDegree[b]++;
    }

    int maxNum = 0;

    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 1) {
            maxNum = max(maxNum, bfs(i));
            fill(visited, visited + 10001, false);
        }
    }

    cout << maxNum;

}
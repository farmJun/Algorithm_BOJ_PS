#include "iostream"
#include "vector"
#include "queue"
#include "algorithm"

using namespace std;

vector<pair<int, int>> graph[100001];
bool visited[100001];

int bfs(int start) {
    queue<pair<int, int>> q;

    q.push({start, 0});

    int number = 0;
    int ret = 0;
    while (!q.empty()) {
        int front = q.front().first;
        int count = q.front().second;
        q.pop();


        ret = count > number ? front : ret;
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

    return ret;
}

int bfs2(int start, int end) {
    queue<pair<int, int>> q;

    q.push({start, 0});

    while (!q.empty()) {
        int front = q.front().first;
        int count = q.front().second;
        q.pop();

        if(front == end){
            return count;
        }

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

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, c;

        cin >> a;

        while (true) {
            cin >> b;

            if (b == -1) {
                break;
            }

            cin >> c;

            graph[a].push_back({b, c});
        }
    }

    int start = bfs(1);
    fill(visited, visited + 100001, false);

    int end = bfs(start);
    fill(visited, visited + 100001, false);

    int ans = bfs2(start, end);
    cout << ans;
}
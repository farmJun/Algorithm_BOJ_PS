#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> graph[1001];
bool visited[1001];

void dfs(int x) {
    visited[x] = true;
    for (auto i: graph[x]) {
        if (!visited[i]) dfs(i);
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        if (visited[front]) continue;
        visited[front] = true;

        for (auto i: graph[front]) {
            if (!visited[i]) q.push(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            //bfs(i);
            dfs(i);
            cnt++;
        }
    }

    cout << cnt;
}
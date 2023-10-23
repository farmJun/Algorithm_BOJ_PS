#include "iostream"
#include "queue"
#include "algorithm"

using namespace std;

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

int l;
int visited[301][301];
int graph[301][301];

void bfs(int startX, int startY, int endX, int endY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    int cnt = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        if (x == endX && y == endY) {
            cout << graph[x][y] << endl;
            return;
        }

        for (int i = 0; i < 8; i++) {
            int x2 = x + dx[i];
            int y2 = y + dy[i];

            if (x2 < 0 || y2 < 0 || x2 >= l || y2 >= l) {
                continue;
            }

            if (!visited[x2][y2]) {
                visited[x2][y2] = true;
                q.push({x2, y2});
                graph[x2][y2] = graph[x][y] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> l;

        int a, b, c, d;
        cin >> a >> b >> c >> d;

        bfs(a, b, c, d);
        fill(&visited[0][0], &visited[300][301], false);
        fill(&graph[0][0], &graph[300][301], 0);

    }

}
#include "iostream"
#include "queue"

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int tomato[1001][1001];
bool visited[1001][1001];
int n, m;
queue<pair<int, int>> q;

void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x2 = x + dx[i];
            int y2 = y + dy[i];

            if (x2 < 0 || y2 < 0 || x2 >= n || y2 >= m) {
                continue;
            }

            if (tomato[x2][y2] == 0 && !visited[x2][y2]) {
                visited[x2][y2] = true;
                tomato[x2][y2] = tomato[x][y] + 1;
                q.push({x2, y2});
            }
        }
    }
}

int main() {
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tomato[i][j];

            if (tomato[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    bfs();

    int maxNum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tomato[i][j] == 0) {
                cout << -1;
                return 0;
            }
            maxNum = max(maxNum, tomato[i][j]);
        }
    }
    cout << maxNum - 1;
}

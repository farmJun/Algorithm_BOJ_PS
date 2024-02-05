#include "iostream"
#include "queue"

using namespace std;

int n, m, maxPainting, number, map[501][501], visit[501][501];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visit[y][x] = 1;
    int count = 0;

    while (!q.empty()) {
        int curX = q.front().second;
        int curY = q.front().first;
        count++;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                continue;
            }

            if (map[ny][nx] == 0) {
                continue;
            }

            if (!visit[ny][nx]) {
                visit[ny][nx] = 1;
                q.push({ny, nx});
            }
        }
    }

    return count;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1 && visit[i][j] == 0) {
                maxPainting = max(bfs(i, j), maxPainting);
                number++;
            }
        }
    }

    cout << number << '\n' << maxPainting;

}
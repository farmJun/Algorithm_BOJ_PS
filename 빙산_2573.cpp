#include "iostream"
#include "queue"
#include "cstring"

using namespace std;

int n, m, map[301][301];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visit[301][301];


int count(int y, int x) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (map[ny][nx] == 0 && !visit[ny][nx]) {
            cnt++;
        }
    }

    return cnt;
}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visit[y][x] = true;

    while (!q.empty()) {
        int curX = q.front().second;
        int curY = q.front().first;
        q.pop();

        int sea = count(curY, curX);
        map[curY][curX] = (map[curY][curX] < sea) ? 0 : map[curY][curX] - sea;

        for (int i = 0; i < 4; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if (map[ny][nx] == 0) {
                continue;
            }

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                continue;
            }

            if (!visit[ny][nx]) {
                visit[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
}

void bfs2(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visit[y][x] = true;

    while (!q.empty()) {
        int curX = q.front().second;
        int curY = q.front().first;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if (map[ny][nx] == 0) {
                continue;
            }

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                continue;
            }

            if (!visit[ny][nx]) {
                visit[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
}

bool check() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] != 0 && !visit[i][j]) {
                bfs2(i, j);
                cnt++;

                if (cnt > 1) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] != 0 && !visit[i][j]) {
                while (map[i][j] != 0) {
                    if (!check()) {
                        cout << ans;
                        return 0;
                    }
                    memset(visit, false, sizeof(visit));

                    bfs(i, j);
                    ans++;
                    memset(visit, false, sizeof(visit));
                }
            }
        }
    }

    cout << 0;
}
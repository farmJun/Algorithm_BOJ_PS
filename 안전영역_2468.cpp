#include "iostream"
#include "queue"

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int map[101][101];
bool visited[101][101];
int n;

void dfs(int x, int y, int h) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int x2 = x + dx[i];
        int y2 = y + dy[i];

        if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= n) {
            continue;
        }

        if (map[x2][y2] > h && !visited[x2][y2]) {
            dfs(x2, y2, h);
        }
    }

}

void bfs(int x, int y, int h) {
    queue<pair<int, int>> q;
    q.push({x, y});

    while (!q.empty()) {
        int x1 = q.front().first;
        int y1 = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x2 = x1 + dx[i];
            int y2 = y1 + dy[i];

            if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= n) {
                continue;
            }

            if (map[x2][y2] > h && !visited[x2][y2]) {
                visited[x2][y2] = true;
                q.push({x2, y2});
            }
        }
    }
}

int main() {

    cin >> n;
    int maxH = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] > maxH) {
                maxH = map[i][j];
            }
        }
    }

    int cnt = 0;

    for (int h = 0; h <= maxH; h++) {

        int nowCnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] > h && !visited[i][j]) {
                    bfs(i, j, h);
                    //bfs
                    nowCnt++;
                }
            }
        }

        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                visited[i][j] = false;
            }
        }

        cnt = max(cnt, nowCnt);
    }


    cout << cnt;
}
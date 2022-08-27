#include "iostream"
#include "queue"

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

char map[51][51];
bool visited[51][51];
int dist[51][51];

int n, m;

int bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({x, y});

    visited[y][x] = true;
    int maxNum = 0;

    while (!q.empty()) {
        int x1 = q.front().first;
        int y1 = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x2 = x1 + dx[i];
            int y2 = y1 + dy[i];

            if (x2 < 0 || y2 < 0 || x2 >= m || y2 >= n) {
                continue;
            }

            if(map[y2][x2]=='W'){
                continue;
            }

            if (!visited[y2][x2]) {
                visited[y2][x2] = true;
                q.push({x2, y2});
                dist[y2][x2] = dist[y1][x1] + 1;
                maxNum = max(maxNum, dist[y2][x2]);
            }
        }
    }
    return maxNum ;
}

void reset() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = false;
            dist[i][j] = 0;
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int maxNum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'L') {
                maxNum = max(maxNum, bfs(i, j));
                reset();
            }
        }
    }

    cout << maxNum;

}
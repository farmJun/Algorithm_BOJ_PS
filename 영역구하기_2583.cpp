#include "iostream"
#include "queue"
#include "algorithm"

using namespace std;

int m, n, k, x, y, x2, y2;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visit[101][101];

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visit[x][y] = true;
    int size = 0;

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        size++;

        for (int i = 0; i < 4; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }

            if (!visit[nx][ny]) {
                visit[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return size;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> m >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> x >> y >> x2 >> y2;
        for (int i = x; i < x2; i++) {
            for (int j = y; j < y2; j++) {
                visit[i][j] = true;
            }
        }
    }

    int cnt = 0;
    priority_queue<int, vector<int>, greater<int>> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visit[i][j]) {
                cnt++;
                ans.push(bfs(i, j));
            }
        }
    }

    cout << cnt << '\n';
    while (!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
    }
}
#include "iostream"
#include "queue"

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int miro[101][101];
bool visited[101][101];
int n, m;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x2 = x + dx[i];
            int y2 = y + dy[i];

            if (miro[x2][y2] == 0) {
                continue;
            }
            if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) {
                continue;
            }

            if (!visited[x2][y2]) {
                visited[x2][y2] = true;
                miro[x2][y2] = miro[x][y] + 1;
                q.push({x2, y2});
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++) {
            miro[i][j] = s[j] - '0';
        }
    }

    bfs(0, 0);

    cout << miro[n - 1][m - 1];

}
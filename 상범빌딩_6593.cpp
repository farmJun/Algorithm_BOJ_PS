#include "iostream"
#include "queue"

using namespace std;

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int l, r, c;

char building[31][31][31];
bool visited[31][31][31];
int dist[31][31][31];

void reset() {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) {
                building[i][j][k] = 0;
                visited[i][j][k] = 0;
                dist[i][j][k] = 0;
            }
        }
    }
}

struct Q {
    int z;
    int y;
    int x;
};

void bfs(int z, int y, int x) {
    queue<Q> q;
    q.push({z, y, x});
    visited[z][y][x] = true;

    while (!q.empty()) {
        int y1 = q.front().y;
        int x1 = q.front().x;
        int z1 = q.front().z;
        q.pop();

        for (int i = 0; i < 6; i++) {
            int y2 = y1 + dy[i];
            int x2 = x1 + dx[i];
            int z2 = z1 + dz[i];

            if (x2 < 0 || y2 < 0 || z2 < 0 || x2 >= c || y2 >= r || z2 >= l) {
                continue;
            }

            if (building[z2][y2][x2] == '#') {
                continue;
            }

            if (building[z2][y2][x2] == 'E') {
                dist[z2][y2][x2] = dist[z1][y1][x1] + 1;
                cout << "Escaped in " << dist[z2][y2][x2] << " minute(s).\n";
                return;
            }

            if (building[z2][y2][x2] == '.' && !visited[z2][y2][x2]) {
                q.push({z2, y2, x2});
                visited[z2][y2][x2] = true;
                dist[z2][y2][x2] = dist[z1][y1][x1] + 1;
            }
        }
    }
    cout << "Trapped!\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cin >> l >> r >> c;

        if (l == 0 && r == 0 && c == 0) {
            break;
        }

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    cin >> building[i][j][k];
                }
            }
        }

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    if (building[i][j][k] == 'S') {
                        bfs(i, j, k);
                    }
                }
            }
        }

        reset();
    }


}
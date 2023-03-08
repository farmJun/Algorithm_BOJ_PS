#include "iostream"
#include "queue"

using namespace std;

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int map[101][101][101];
bool visited[101][101][101];

int n, m, h;

struct Node {
    int x, y, z;

    Node(int x, int y, int z) : x(x), y(y), z(z) {}
};

queue<Node> tomato;

void bfs() {

    while (!tomato.empty()) {
        int x = tomato.front().x;
        int y = tomato.front().y;
        int z = tomato.front().z;
        tomato.pop();

        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) {
                continue;
            }

            if (!visited[nz][ny][nx] && map[nz][ny][nx] == 0) {
                visited[nz][ny][nx] = true;
                map[nz][ny][nx] = map[z][y][x] + 1;
                tomato.push(Node(nx, ny, nz));
            }
        }
    }
}


int main() {
    cin >> m >> n >> h;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> map[i][j][k];

                if (map[i][j][k] == 1) {
                    tomato.push(Node(k, j, i));
                }
            }
        }
    }

    bfs();
    int maxV = 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (map[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                }
                maxV = max(maxV, map[i][j][k]);
            }
        }
    }

    cout << maxV - 1;


}
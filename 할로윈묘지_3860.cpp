#include "iostream"
#include "vector"
#include "queue"

#define MAX 123456789

using namespace std;

int w, h, g, e;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int map[31][31];
long long dist[31][31];
bool isMinus = false;

struct Hole {
    int x1, y1, x2, y2, t;

    Hole(int x1, int y1, int x2, int y2, int t) : x1(x1), y1(y1), x2(x2), y2(y2), t(t) {}
};

vector<Hole> hole;

void bellmanFord() {
    dist[0][0] = 0;

    for (int i = 0; i < w * h; i++) {
        for (auto next: hole) {
            int toX = next.x2;
            int toY = next.y2;

            int fromX = next.x1;
            int fromY = next.y1;

            if (dist[toY][toX] > dist[fromY][fromX] + next.t && dist[fromY][fromX] != MAX) {
                dist[toY][toX] = dist[fromY][fromX] + next.t;
            }
        }
    }


    for (auto next: hole) {
        int toX = next.x2;
        int toY = next.y2;

        int fromX = next.x1;
        int fromY = next.y1;
        if (dist[toY][toX] > dist[fromY][fromX] + next.t && dist[fromY][fromX] != MAX) {
            isMinus = true;
            return;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0) {
            return 0;
        }
        cin >> g;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                map[i][j] = 0;
            }
        }

        for (int i = 0; i < g; i++) {
            int x1, y1;
            cin >> x1 >> y1;
            map[y1][x1] = -1; // 묘비
        }

        cin >> e;
        for (int i = 0; i < e; i++) {
            int x1, y1, x2, y2, t;
            cin >> x1 >> y1 >> x2 >> y2 >> t; // 구멍
            map[y1][x1] = -2;
            hole.push_back(Hole(x1, y1, x2, y2, t));
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {

                if (map[i][j] != 0 || (i == h - 1 && j == w - 1)) {
                    continue;
                }

                for (int k = 0; k < 4; k++) {
                    int nx = j + dx[k];
                    int ny = i + dy[k];

                    if (ny >= 0 && ny < h && nx >= 0 && nx < w && map[ny][nx] != -1) {
                        hole.push_back(Hole(j, i, nx, ny, 1));
                    }
                }
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                dist[i][j] = 123456789;
            }
        }

        bellmanFord();

        if (isMinus) {
            cout << "Never\n";
        } else {
            if (dist[h - 1][w - 1] == MAX) {
                cout << "Impossible\n";
            } else {
                cout << dist[h - 1][w - 1] << '\n';
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                map[i][j] = 0;
                dist[i][j] = 0;
            }
        }
        hole.clear();
        isMinus = false;
    }
}

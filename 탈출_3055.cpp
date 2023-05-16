#include "iostream"
#include "queue"

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int R, C;

char map[51][51];
int visited[51][51];

struct Node {
    int y, x;
    char type;

    Node(int y, int x, char type) {
        this->y = y;
        this->x = x;
        this->type = type;
    }
};

queue<Node> q;

void bfs() {

    while (!q.empty()) {
        Node node = q.front();
        q.pop();
        int x = node.x;
        int y = node.y;
        char type = node.type;

        if (type == 'D') {
            cout << visited[y][x];
            exit(0);
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (ny < 0 || ny >= R || nx < 0 || nx >= C) {
                continue;
            }

            if (type == 'S' || type == '.') {
                if ((map[ny][nx] == '.' || map[ny][nx] == 'D') && visited[ny][nx] == 0) {
                    visited[ny][nx] = visited[y][x] + 1;
                    q.push(Node{ny, nx, map[ny][nx]});
                }
            } else if (type == '*') {
                if (map[ny][nx] == '.' || map[ny][nx] == 'S') {
                    map[ny][nx] = '*';
                    q.push(Node{ny, nx, '*'});
                }
            }
        }
    }
    cout << "KAKTUS";
}

int main() {
    cin >> R >> C;

    int startX, startY;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'S') {
                startX = j;
                startY = i;
            }
            if (map[i][j] == '*') {
                q.push(Node{i, j, '*'});
            }
        }
    }

    q.push(Node{startY, startX, 'S'});
    bfs();
}
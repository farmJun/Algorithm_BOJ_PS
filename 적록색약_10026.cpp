#include "iostream"

using namespace std;


int n;

char map[101][101];
bool visited[101][101];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
            continue;
        }
        if (!visited[nx][ny] && map[x][y] == map[nx][ny]) {
            dfs(nx, ny);
        }
    }
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;

        for (int j = 0; j < n; j++) {
            map[i][j] = line[j];
        }
    }
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                dfs(i, j);
                count++;
            }
        }
    }

    cout << count << ' ';
    count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 'G') {
                map[i][j] = 'R';
            }
            visited[i][j] = false;
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                dfs(i, j);
                count++;
            }
        }
    }

    cout << count;
}
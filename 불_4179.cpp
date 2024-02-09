#include "iostream"
#include "queue"

using namespace std;

char map[1001][1001];
int n, m, fire[1001][1001], jihun[1001][1001];
queue<pair<int, int>> fireQ;
queue<pair<int, int>> jihunQ;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfsFire() {
    while (!fireQ.empty()) {
        int curX = fireQ.front().second;
        int curY = fireQ.front().first;
        fireQ.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                continue;
            }

            if (map[ny][nx] == '#') {
                continue;
            }

            if (fire[ny][nx] < 0) {
                fire[ny][nx] = fire[curY][curX] + 1;
                fireQ.push({ny, nx});
            }
        }
    }
}


void bfsJihun() {
    while (!jihunQ.empty()) {
        int curX = jihunQ.front().second;
        int curY = jihunQ.front().first;
        jihunQ.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                cout << jihun[curY][curX] + 1;
                return;
            }

            if (map[ny][nx] == '#') {
                continue;
            }

            if (fire[ny][nx] >= 0 && jihun[curY][curX] + 1 >= fire[ny][nx]) {
                continue;
            }

            if (jihun[ny][nx] < 0) {
                jihun[ny][nx] = jihun[curY][curX] + 1;
                jihunQ.push({ny, nx});
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    fill(fire[0], fire[n + 1], -1);
    fill(jihun[0], jihun[n + 1], -1);


    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            map[i][j] = s[j];

            if (map[i][j] == 'F') {
                fireQ.push({i, j});
                fire[i][j] = 0;
                continue;
            }

            if (map[i][j] == 'J') {
                jihunQ.push({i, j});
                jihun[i][j] = 0;
            }
        }
    }

    bfsFire();
    bfsJihun();
}
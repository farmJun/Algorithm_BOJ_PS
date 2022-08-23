#include "iostream"
#include "queue"
#include "vector"
#include "algorithm"

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int map[9][9];
int copyMap[9][9];
int n, m;

int maxNum = 0;

queue<pair<int, int>> virus;

void reset() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            copyMap[i][j] = map[i][j];
        }
    }
}

void bfs() {

    queue<pair<int, int>> q = virus;

    while (!q.empty()) {
        int y1 = q.front().first;
        int x1 = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int y2 = y1 + dy[i];
            int x2 = x1 + dx[i];

            if (x2 < 0 || y2 < 0 || x2 >= m || y2 >= n) {
                continue;
            }

            if (copyMap[y2][x2] == 1) {
                continue;
            }

            if (copyMap[y2][x2] == 0) {
                copyMap[y2][x2] = 2;
                q.push({y2, x2});
            }
        }
    }
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (copyMap[i][j] == 0) {
                cnt++;
            }
        }
    }

    maxNum = max(maxNum, cnt);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;

    vector<pair<int, int>> blank;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];

            if (map[i][j] == 2) {
                virus.push({i, j});
            } else if (map[i][j] == 0) {
                blank.push_back({i, j});
            }

        }
    }

    vector<bool> temp(blank.size(), false);

    for (int i = 0; i < 3; i++) {
        temp[i] = true;
    }

    do {
        reset();

        for (int i = 0; i < blank.size(); i++) {
            if (temp[i]) {
                copyMap[blank[i].first][blank[i].second] = 1;
            }
        }

       bfs();
    } while (prev_permutation(temp.begin(), temp.end()));

    cout << maxNum;

}
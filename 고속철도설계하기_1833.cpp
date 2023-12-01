#include "iostream"
#include "queue"
#include "vector"
#include "cmath"

using namespace std;

priority_queue <pair<int, pair < int, int>>, vector <pair<int, pair < int, int>>>, greater <pair<int,
        pair < int, int>>>>
q;

int par[201];
int map[201][201];
bool visit[201][201];
vector <pair<int, int>> ansV;
int ans;
int cnt;

int find(int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

void doUnion(int x1, int y1) {
    int x = find(x1);
    int y = find(y1);

    par[y] = x;
}

void mst() {

    while (!q.empty()) {
        int from = q.top().second.first;
        int to = q.top().second.second;
        double cost = q.top().first;
        q.pop();

        if (find(from) != find(to)) {
            cnt++;
            doUnion(from, to);
            ansV.push_back({from, to});
            ans += cost;
        }
    }
    cout << ans << " " << cnt << "\n";
    for (auto a: ansV) {
        cout << a.first << " " << a.second << "\n";
    }
}

int main() {

    int n, cost;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (map[i][j] < 0) {
                if (!visit[i][j]) {
                    doUnion(i, j);
                    ans += abs(map[i][j]);
                    visit[j][i] = true;
                }
            } else if (map[i][j] > 0) {
                if (!visit[i][j]) {
                    q.push({map[i][j], {i, j}});
                    visit[j][i] = true;
                }
            }
        }
    }


    mst();


}
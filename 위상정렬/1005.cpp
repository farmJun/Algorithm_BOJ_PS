#include "iostream"
#include "vector"
#include "queue"

using namespace std;

int t, n, k, x, y, w;

vector<int> graph[1001];
int cost[1001];
int ans[1001];
int inDegree[1001];

void bfs() {
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            ans[i] = cost[i];
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i: graph[cur]) {
            ans[i] = max(ans[i], ans[cur] + cost[i]);
            inDegree[i]--;
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
    }
    cout << ans[w] << "\n";
}

int main() {
    cin >> t;

    while (t--) {

        cin >> n >> k;

        for (int i = 1; i <= n; i++) {
            cin >> cost[i];
        }

        while (k--) {
            cin >> x >> y;
            graph[x].push_back(y);
            inDegree[y]++;
        }

        cin >> w;

        bfs();

        fill(cost, cost + 1001, 0);
        fill(ans, ans + 1001, 0);
        fill(inDegree, inDegree + 1001, 0);
        for (int i = 0; i < 1001; i++) {
            graph[i].clear();
        }

    }


}
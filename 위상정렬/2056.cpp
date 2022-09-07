#include "iostream"
#include "vector"
#include "queue"

using namespace std;

int n, k;

vector<int> graph[10001];
int cost[10001];
int ans[10001];
int inDegree[10001];

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
}

int main() {

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int c, t;
        cin >> c >> t;

        while (t--) {
            int a;
            cin >> a;
            graph[a].push_back(i);
            inDegree[i]++;
        }
        cost[i] = c;

    }

    bfs();

    int res = 0;

    for (int i = 1; i <= n; i++) {
        res = max(res, ans[i]);
    }

    cout << res;
}
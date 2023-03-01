#include "iostream"
#include "vector"
#include "set"
#include "algorithm"

using namespace std;

int v, e;

vector<int> adj[1000001];
int dist[1000001];
int distCnt = 1;
set<pair<int, int>> ans;

int dfs(int cur, int before) {
    dist[cur] = distCnt;
    distCnt++;

    int ret = dist[cur];

    for (auto child: adj[cur]) {
        if (child == before) {
            continue;
        }

        if (dist[child]) {
            ret = min(ret, dist[child]);
            continue;
        }

        int prev = dfs(child, cur);
        if (prev > dist[cur]) {
            ans.insert({min(cur, child), max(cur, child)});
        }
        ret = min(ret, prev);

    }

    return ret;
}

int main() {
    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    distCnt = 1;

    for (int i = 1; i <= v; i++) {
        if (dist[i] == 0) {
            dfs(i, 0);
        }
    }
    cout << ans.size() << "\n";
    for (auto a: ans) {
        cout << a.first << ' ' << a.second << '\n';
    }

}
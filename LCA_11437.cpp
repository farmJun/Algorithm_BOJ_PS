#include "iostream"
#include "vector"
#include "algorithm"
#include "cstring"

using namespace std;

int n, m;
vector<int> adj[50001];
int parent[50001][21];
int depth[50001];

void makeTree(int cur) {
    for (int next: adj[cur]) {
        if (depth[next] == -1) {
            parent[next][0] = cur;
            depth[next] = depth[cur] + 1;
            makeTree(next);
        }
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(parent, -1, sizeof(parent));
    fill(depth, depth + n + 1, -1);

    depth[1] = 0;
    makeTree(1);

    for (int j = 0; j < 20; j++) {
        for (int i = 1; i <= n; i++) {
            int k = parent[i][j];
            if (k != -1) {
                parent[i][j + 1] = parent[k][j];
            }
        }
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        if (depth[u] < depth[v]) {
            swap(u, v);
        }
        int diff = depth[u] - depth[v];
        int j = 0;

        while (diff) {
            if (diff % 2) {
                u = parent[u][j];
            }
            j++;
            diff /= 2;
        }

        if (u != v) {
            for (int k = 20; k >= 0; k--) {
                if (parent[u][k] != parent[v][k]) {
                    u = parent[u][k];
                    v = parent[v][k];
                }
            }

            u = parent[u][0];
        }

        cout << u << "\n";
    }
}
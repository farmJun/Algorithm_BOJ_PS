#include "iostream"
#include "vector"
#include "algorithm"
#include "cstring"

using namespace std;

int parent[50001][21]; // 20은 안됨, 21????
vector<int> adj[50001];
int depth[50001];
int t, n, a, b, u, v;

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

    cin >> t;
    for (int tc = 0; tc < t; tc++) {

        for (int i = 0; i < 50001; i++) {
            adj[i].clear();
            depth[i] = 0;

            for (int j = 0; j < 21; j++) {
                parent[i][j] = -1;
            }
        }

        cin >> n;


        for (int i = 0; i < n - 1; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            depth[b]++;
        }

        int root;

        for (int i = 1; i <= n; i++) {
            if (depth[i] == 0) {
                root = i;
            }
        }
        memset(parent, -1, sizeof(parent));
        fill(depth, depth + n + 1, -1);

        depth[root] = 0;
        makeTree(root);

        for (int j = 0; j < 21; j++) {
            for (int i = 1; i <= n; i++) {
                int k = parent[i][j];
                if (k != -1) {
                    parent[i][j + 1] = parent[k][j];
                }
            }
        }

        cin >> u >> v;

        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        int diff = depth[u] - depth[v];

        int cnt = 0;
        while (diff) {
            if (diff % 2) {
                u = parent[u][cnt];
            }
            cnt++;
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
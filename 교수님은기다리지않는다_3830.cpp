#include "iostream"

using namespace std;

int n, m;
int node[100001];
long long dist[100001];


int find(int a) {
    if (node[a] < 0) {
        return a;
    }
    int result = find(node[a]);
    dist[a] += dist[node[a]];
    return node[a] = result;
}

void merge(int a, int b, int diff) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA == rootB) {
        return;
    }

    int newDist = dist[a] + diff;
    int originDist = dist[b];

    dist[rootB] = newDist - originDist;
    node[rootB] = rootA;
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }

        for (int i = 1; i <= n; i++) {
            node[i] = -1;
            dist[i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int a, b, w;
            char c;
            cin >> c >> a >> b;

            if (c == '!') {
                cin >> w;
                merge(a, b, w);
            } else {
                if (find(a) == find(b)) {
                    cout << dist[b] - dist[a] << "\n";
                } else {
                    cout << "UNKNOWN\n";
                }
            }
        }
    }
}

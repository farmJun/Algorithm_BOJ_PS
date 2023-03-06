#include "iostream"
#include "vector"

using namespace std;

int n, m, a, b, c;

vector<pair<int, int>> graph[501];
long long dist[501];
bool isMinus = false;

void bellmanFord() {
    for (int i = 1; i <= n; i++) {
        dist[i] = 123456789;
    }
    dist[1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (auto a: graph[j]) {
                if (dist[a.first] > dist[j] + a.second && dist[j] != 123456789) {
                    dist[a.first] = dist[j] + a.second;
                }
            }
        }
    }

    for (int j = 1; j <= n; j++) {
        for (auto a: graph[j]) {
            if (dist[a.first] > dist[j] + a.second && dist[j] != 123456789) {
                isMinus = true;
                return;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    bellmanFord();

    if (isMinus) {
        cout << -1;
    } else {
        for (int i = 2; i <= n; i++) {
            if (dist[i] == 123456789) {
                cout << -1;
            } else {
                cout << dist[i];
            }
            cout << '\n';
        }
    }
}
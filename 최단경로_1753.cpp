#include "iostream"
#include "queue"
#include "vector"
#include "climits"

using namespace std;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

vector<pair<int, int>> graph[20001];
int dist[20001];
int V, E, K;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> V >> E >> K;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    for (int i = 1; i <= V; i++) {
        dist[i] = INT_MAX;
    }
    dist[K] = 0;
    pq.push({K, 0});

    while (!pq.empty()) {
        int vertex = pq.top().first;
        int cost = pq.top().second;
        pq.pop();

        if (dist[vertex] < cost) {
            continue;
        }

        for (auto adj: graph[vertex]) {
            if (dist[adj.first] > cost + adj.second) {
                dist[adj.first] = cost + adj.second;
                pq.push({adj.first, dist[adj.first]});
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INT_MAX) {
            cout << "INF\n";
        } else {
            cout << dist[i] << "\n";
        }
    }
}
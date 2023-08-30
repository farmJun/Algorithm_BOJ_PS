#include "iostream"
#include "vector"
#include "queue"

using namespace std;

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
int n;
int node[1001];
int map[1001][1001];

int find(int x) {
    if (node[x] < 0) {
        return x;
    }

    return node[x] = find(node[x]);
}

void merge(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA == rootB) {
        return;
    }

    node[rootB] = rootA;
}

void mst() {
    for (int i = 0; i < n; i++) {
        node[i] = -1;
    }

    long long total = 0;

    while (!q.empty()) {
        int cost = q.top().first;
        int from = q.top().second.first;
        int to = q.top().second.second;
        q.pop();

        if (find(from) != find(to)) {
            merge(from, to);
            total += cost;
        }
    }

    cout << total;
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            q.push({map[i][j], {i, j}});
        }
    }

    mst();
}
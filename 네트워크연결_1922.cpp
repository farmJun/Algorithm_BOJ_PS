#include "iostream"
#include "queue"
#include "vector"

using namespace std;

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

int a, b, c, n, m;
int total = 0;
int node[1001];

int find(int a) {
    if (node[a] < 0) {
        return a;
    }

    return node[a] = find(node[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) {
        return;
    }

    node[b] = a;
}

void mst() {
    for (int i = 1; i <= n; i++) {
        node[i] = -1;
    }

    while (!q.empty()) {
        int from = q.top().second.first;
        int to = q.top().second.second;
        int cost = q.top().first;
        q.pop();

        if (find(from) != find(to)) {
            merge(from, to);
            total += cost;
        }
    }
}



int main() {

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        q.push({c, {a, b}});
    }

    mst();
    cout << total;
}


#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int node[100001];
vector<pair<int, pair<int, int>>> v;
int n, m;

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

    int total = 0;
    int maxCost = 0;
    for (int i = 0; i < v.size(); i++) {
        int cost = v[i].first;
        int from = v[i].second.first;
        int to = v[i].second.second;

        if (find(from) != find(to)) {
            merge(from, to);
            total += cost;
            maxCost = max(maxCost, cost);
        }
    }

    cout << total - maxCost;
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        v.push_back({cost, {from, to}});
    }

    sort(v.begin(), v.end());

    mst();
}
#include "iostream"
#include "queue"
#include "vector"

using namespace std;

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> copyQ;

int n, m, a, b, k;
int par[10001];

int find(int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

void merge(int x1, int y1) {
    int x = find(x1);
    int y = find(y1);

    par[y] = x;
}

void mst() {
    int total = 0;

    while (!q.empty()) {
        int from = q.top().second.first;
        int to = q.top().second.second;
        int cost = q.top().first;
        q.pop();
        cout << cost << " " << from << " " << to << endl;

        if (find(from) != find(to)) {
            merge(from, to);
            total += cost;
        }
    }

    cout << total << "\n\n";
}

void init() {
    for (int i = 1; i <= 10001; i++) {
        par[i] = i;
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        q.push({i, {a, b}});
    }

    copyQ = q;
    init();
    mst();
    copyQ.pop();
    q = copyQ;

    init();
    mst();




}
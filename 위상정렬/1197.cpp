#include "iostream"
#include "queue"
#include "vector"

using namespace std;

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
int v, e, a, b, c;
int par[10001];

int find(int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

void doUnion(int x1, int y1) {
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

        if (find(from) != find(to)) {
            doUnion(from, to);
            total += cost;
        }
    }

    cout << total;
}

int main() {
    cin >> v >> e;


    while (e--) {
        cin >> a >> b >> c;
        q.push({c, {a, b}});
    }

    for (int i = 1; i <= v; i++) {
        par[i] = i;
    }

    mst();
}
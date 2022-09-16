#include "iostream"
#include "queue"
#include "vector"

using namespace std;

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
int n, m, k, a, b;
int par[1000000];
vector<int> ans;

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
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {

    }

    while (m--) {
        cin >> a >> b >> ;
        q.push({c, {a, b}});
    }

    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }

    mst();
}
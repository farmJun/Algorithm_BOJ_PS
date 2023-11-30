#include "iostream"
#include "queue"
#include "vector"

using namespace std;

priority_queue <pair<int, pair < int, int>>, vector <pair<int, pair < int, int>>>, greater <pair<int,
        pair < int, int>>>>
q;

int n, m, a, b, c;
int par[100001];
long long all;

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
    int cnt = 0;
    while (!q.empty()) {
        int from = q.top().second.first;
        int to = q.top().second.second;
        int cost = q.top().first;
        q.pop();

        if (find(from) != find(to)) {
            doUnion(from, to);
            cnt++;
            all -= cost;
        }
    }
    if (cnt == n - 1) {
        cout << all;
    } else {
        cout << -1;
    }
}

int main() {

    cin >> n >> m;


    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }

    while (m--) {
        cin >> a >> b >> c;
        q.push({c, {a, b}});
        all += c;
    }


    mst();
}
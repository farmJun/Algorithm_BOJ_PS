#include "iostream"
#include "queue"
#include "vector"
#include "cmath"

using namespace std;

priority_queue <pair<double, pair < int, int>>, vector <pair<double, pair < int, int>>>, greater <pair<double,
        pair < int, int>>>>
q;

int par[101];

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
    double total = 0;

    while (!q.empty()) {
        int from = q.top().second.first;
        int to = q.top().second.second;
        double cost = q.top().first;
        q.pop();

        if (find(from) != find(to)) {
            doUnion(from, to);
            total += cost;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << total;
}

int main() {

    int n;
    double x, y;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }

    vector <pair<int, int>> xy;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        xy.push_back({x, y});
    }


    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int distX = abs(xy[i].first - xy[j].first);
            int distY = abs(xy[i].second - xy[j].second);
            double dist = sqrt(pow(distX, 2) + pow(distY, 2));
            q.push({dist, {i + 1, j + 1}});
        }
    }

    mst();

}
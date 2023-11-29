#include "iostream"
#include "queue"
#include "vector"

using namespace std;

int n, m, a, b, c;
int par[100001];

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
    /*while (!q.empty()) {
        int from = q.top().second.first;
        int to = q.top().second.second;
        int cost = q.top().first;
        q.pop();

        if (find(from) != find(to)) {
            doUnion(from, to);
            all -= cost;
        }
    }
    cout << all;*/
}

int main() {

    while (true) {
        cin >> m >> n;

        if (m == 0 && n == 0) {
            break;
        }

        for (int i = 0; i < m; i++) {
            par[i] = i;
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        long long all = 0;

        while (n--) {
            cin >> a >> b >> c;
            q.push({c, {a, b}});
            all += c;
        }

        while (!q.empty()) {
            int from = q.top().second.first;
            int to = q.top().second.second;
            int cost = q.top().first;
            q.pop();

            if (find(from) != find(to)) {
                doUnion(from, to);
                all -= cost;
            }
        }
        cout << all << "\n";
    }

}
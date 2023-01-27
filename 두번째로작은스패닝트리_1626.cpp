#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int n, m;
vector<pair<int, int>> adj[50001];
int parent[50001][17];
int Depth[50001];
int node[50001];
pair<int, int> Biggest[50001][17];

struct Edge {
    int A, B, W;
    bool used = false;

    Edge() : Edge(0, 0, 0) {}

    Edge(int a, int b, int w) : A(a), B(b), W(w) {}
};

vector<Edge> vec;

bool cmp(Edge &a, Edge &b) {
    return a.W < b.W;
}

int find(int a) {
    if (node[a] == 0) {
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


int GetPlusByLCA(Edge EE) {
    int x = EE.A;
    int y = EE.B;
    int w = EE.W;
    //대체가능한 간선의 가장 큰 가중치. W 와 달라야한다.
    int ret = -1;
    if (Depth[x] < Depth[y]) {
        swap(x, y);
    }
    int diff = Depth[x] - Depth[y];
    int cnt = 0;
    while (diff) {
        if (diff % 2 == 1) {
            //경로중 가장 큰 가중치
            if (Biggest[x][cnt].first != w) {
                ret = max(ret, Biggest[x][cnt].first);
            }//경로중 두번째 큰 가중치
            else if (Biggest[x][cnt].second != -1) {
                ret = max(ret, Biggest[x][cnt].second);
            }
            x = parent[x][cnt];
        }

        diff /= 2;
        cnt++;
    }

    if (x != y) {
        for (int i = 16; i >= 0; i--) {
            if (parent[x][i] != parent[y][i]) {
                if (Biggest[x][i].first != w)
                    ret = max(ret, Biggest[x][i].first);
                else if (Biggest[x][i].second != -1)
                    ret = max(ret, Biggest[x][i].second);
                if (Biggest[y][i].first != w)
                    ret = max(ret, Biggest[y][i].first);
                else if (Biggest[y][i].second != -1)
                    ret = max(ret, Biggest[y][i].second);
                x = parent[x][i];
                y = parent[y][i];
            }
        }

        if (Biggest[x][0].first != w)
            ret = max(ret, Biggest[x][0].first);
        else if (Biggest[x][0].second != -1)
            ret = max(ret, Biggest[x][0].second);
        if (Biggest[y][0].first != w)
            ret = max(ret, Biggest[y][0].first);
        else if (Biggest[y][0].second != -1)
            ret = max(ret, Biggest[y][0].second);
        x = parent[x][0];
    }
    return ret;

}

void makeTree(int cur) {
    for (auto next: adj[cur]) {
        if (Depth[next.first] != -0) {
            continue;
        }
        parent[next.first][0] = cur;
        Depth[next.first] = Depth[cur] + 1;

        Biggest[next.first][0] = make_pair(next.second, -1);
        makeTree(next.first);

    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vec.push_back(Edge(a, b, c));
    }

    int mst = 0;
    int cnt = 0;
    sort(vec.begin(), vec.end(), cmp);

    for (int i = 0; i < m; i++) {
        int a = vec[i].A;
        int b = vec[i].B;
        int cost = vec[i].W;

        int aRoot = find(a);
        int bRoot = find(b);

        if (aRoot == bRoot) {
            continue;
        }
        merge(a, b);
        mst += cost;
        vec[i].used = true;
        adj[a].push_back(make_pair(b, vec[i].W));
        adj[b].push_back(make_pair(a, vec[i].W));
        cnt++;
        if (cnt == n - 1) {
            break;
        }
    }

    if (cnt != n - 1 || m <= n - 1) {
        cout << -1 << "\n";
        return 0;
    }

    Depth[1] = 1;
    makeTree(1);
    for (int k = 0; k <= 16; ++k) {
        for (int i = 1; i <= n; ++i) {
            int Father = parent[i][k];
            if (Father && parent[Father][k] != 0) {
                int w1 = Biggest[i][k].first;
                int w2 = Biggest[i][k].second;

                int f1 = Biggest[Father][k].first;
                int f2 = Biggest[Father][k].second;
                if (w1 > f1) {
                    Biggest[i][k + 1].first = w1;
                    Biggest[i][k + 1].second = max(f1, w2);
                } else if (w1 < f1) {
                    Biggest[i][k + 1].first = f1;
                    Biggest[i][k + 1].second = max(w1, f2);
                } else {
                    Biggest[i][k + 1] = make_pair(w1, max(w2, f2));
                }
                parent[i][k + 1] = parent[Father][k];
            }
        }
    }

    int plus = 123456789;
    for (int i = 0; i < m; i++) {
        if (vec[i].used) {
            continue;
        }
        int t = GetPlusByLCA(vec[i]);
        if (t == -1 || t == vec[i].W) {
            continue;
        }
        plus = min(plus, vec[i].W - t);
    }
    if (plus == 123456789) {
        cout << -1 << "\n";
    } else {
        cout << mst + plus << "\n";
    }
}
#include "iostream"

using namespace std;

int n, m, a, b, oper;
int node[1000001];

int find(int a) {
    if (node[a] < 0) {
        return a;
    }
    node[a] = find(node[a]);
    return node[a];
}


void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
        return;
    }
    node[b] = a;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        node[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        cin >> oper >> a >> b;

        if (oper == 0) {
            merge(a, b);
        } else {
            if (find(a) == find(b)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}
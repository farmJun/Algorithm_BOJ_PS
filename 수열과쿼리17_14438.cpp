#include "iostream"
#include "vector"

using namespace std;

int n, m;
long long arr[100001];
vector<long long> tree;

long long init(int left, int right, int node) {
    if (left == right) {
        return tree[node] = arr[left];
    }
    int mid = (left + right) / 2;
    return tree[node] = min(init(left, mid, node * 2), init(mid + 1, right, node * 2 + 1));
}

long long query(int left, int right, int node, int qLeft, int qRight) {
    if (qRight < left || right < qLeft) {
        return 2e9;
    }
    if (qLeft <= left && right <= qRight) {
        return tree[node];
    } else {
        int mid = (left + right) / 2;
        return min(query(left, mid, node * 2, qLeft, qRight), query(mid + 1, right, node * 2 + 1, qLeft, qRight));
    }
}

void update(int left, int right, int node, int target) {
    if (target < left || right < target) {
        return;
    }

    if (left == right && left == target) {
        tree[node] = arr[target];
    } else {
        int mid = (left + right) / 2;
        update(left, mid, node * 2, target);
        update(mid + 1, right, node * 2 + 1, target);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    tree.resize(4 * n);

    init(1, n, 1);

    cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if (a == 1) {
            arr[b] = c;
            update(1, n, 1, b);
        } else {
            cout << query(1, n, 1, b, c) << '\n';
        }
    }
}
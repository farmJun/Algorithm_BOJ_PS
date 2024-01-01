#include "iostream"
#include "vector"

using namespace std;

int n, q, p, x, oper;

long long arr[1000001];
vector<long long> tree;

long long init(int left, int right, int node) {
    if (left == right) {
        return tree[node] = arr[left];
    }

    int mid = (left + right) / 2;
    return tree[node] = init(left, mid, node * 2) + init(mid + 1, right, node * 2 + 1);
}

long long query(int left, int right, int node, int qLeft, int qRight) {
    if (qRight < left || right < qLeft) {
        return 0;
    } else if (qLeft <= left && right <= qRight) {
        return tree[node];
    } else {
        int mid = (left + right) / 2;
        return query(left, mid, node * 2, qLeft, qRight) + query(mid + 1, right, node * 2 + 1, qLeft, qRight);
    }
}

void update(int left, int right, int node, int target, long long diff) {
    if (target < left || right < target) {
        return;
    } else if (left == right) {
        tree[node] = tree[node] + diff;
    } else {
        int mid = (left + right) / 2;
        update(left, mid, node * 2, target, diff);
        update(mid + 1, right, node * 2 + 1, target, diff);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        arr[i] = 0;
    }

    tree.resize(4 * n);

    init(1, n, 1);

    for (int i = 0; i < q; i++) {
        cin >> oper >> p >> x;
        if (oper == 1) {
            update(1, n, 1, p, x);
        } else {
            cout << query(1, n, 1, p, x) << '\n';
        }
    }
}
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

long long arr[1000001];
vector<long long> tree;
int n, m;

long long init(int left, int right, int node) {
    if (left == right) {
        return tree[node] = arr[left];
    }

    int mid = (left + right) / 2;
    return tree[node] = init(left, mid, node * 2) + init(mid + 1, right, node * 2 + 1);
}


long long query(int left, int right, int node, int queryLeft, int queryRight) {
    if (queryRight < left || right < queryLeft) {
        return 0;
    } else if (queryLeft <= left && right <= queryRight) {
        return tree[node];
    } else {
        int mid = (left + right) / 2;
        return query(left, mid, node * 2, queryLeft, queryRight) +
               query(mid + 1, right, node * 2 + 1, queryLeft, queryRight);
    }
}

void update(int left, int right, int node, int target, long long diff) {
    if (target < left || right < target) {
        return;
    }

    if (left == right) {
        tree[node] = diff;
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

    cin >> n >> m;

    tree.resize(n * 4);

    for (int i = 1; i <= n; i++) {
        arr[i] = 0;
    }

    init(1, n, 1);

    for (int i = 0; i < m; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, n, 1, b, c);
        } else {
            if (b > c) {
                swap(b, c);
            }
            cout << query(1, n, 1, b, c) << '\n';
        }
    }
}
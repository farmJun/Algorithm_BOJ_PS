#include "iostream"
#include "vector"

using namespace std;

long long arr[1000001];
vector<long long> tree;
int n, m;

long long init(int left, int right, int node) {
    if (left == right) {
        return tree[node] = arr[left];
    }

    int mid = (left + right) / 2;
    return tree[node] = min(init(left, mid, node * 2), init(mid + 1, right, node * 2 + 1));
}


long long query(int left, int right, int node, int queryLeft, int queryRight) {
    if (queryRight < left || right < queryLeft) {
        return 2e9;
    } else if (queryLeft <= left && right <= queryRight) {
        return tree[node];
    } else {
        int mid = (left + right) / 2;
        return min(query(left, mid, node * 2, queryLeft, queryRight),
                   query(mid + 1, right, node * 2 + 1, queryLeft, queryRight));
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    tree.resize(n * 4);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    init(1, n, 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << query(1, n, 1, a, b) << '\n';
    }
}


#include "iostream"
#include "vector"

using namespace std;


pair<long, long> arr[100001];
vector<pair<long, long>> tree; //first : value, second : idx
int n, m;

pair<long, long> compare(pair<long, long> a, pair<long, long> b) {
    if (a.first == b.first) {
        return a.second < b.second ? a : b;
    }

    return a.first < b.first ? a : b;
}

pair<long, long> init(int left, int right, int node) {
    if (left == right) {
        return tree[node] = arr[left];
    }

    int mid = (left + right) / 2;
    return tree[node] = compare(init(left, mid, node * 2), init(mid + 1, right, node * 2 + 1));
}


void update(int left, int right, int node, int target, int diff) {
    if (target < left || right < target) {
        return;
    }

    if (left == right && left == target) {
        tree[node].first = diff;
    } else {
        int mid = (left + right) / 2;
        update(left, mid, node * 2, target, diff);
        update(mid + 1, right, node * 2 + 1, target, diff);
        tree[node] = compare(tree[node * 2], tree[node * 2 + 1]);
    }
}

pair<long, long> query(int left, int right, int node, int qLeft, int qRight) {
    if (qRight < left || right < qLeft) {
        return make_pair(2e9, 2e9);
    } else if (qLeft <= left && right <= qRight) {
        return tree[node];
    } else {
        int mid = (left + right) / 2;
        return compare(query(left, mid, node * 2, qLeft, qRight), query(mid + 1, right, node * 2 + 1, qLeft, qRight));
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    tree.resize(4 * n);
    init(1, n, 1);

    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, n, 1, b, c);
        } else {
            cout << query(1, n, 1, b, c).second << '\n';
        }
    }
}
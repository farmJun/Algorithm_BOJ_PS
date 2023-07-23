#include "iostream"
#include "vector"

using namespace std;
typedef long long ll;

pair<ll, ll> arr[1000001];
vector<pair<ll, ll>> tree; //first = value, second = idx;
int n, m;


pair<ll, ll> compare(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.first == b.first) {
        return (a.second < b.second) ? a : b;
    }

    return a.first < b.first ? a : b;
}


pair<ll, ll> init(int left, int right, int node) {
    if (left == right) {
        return tree[node] = arr[left];
    }

    int mid = (left + right) / 2;
    return tree[node] = compare(init(left, mid, node * 2), init(mid + 1, right, node * 2 + 1));
}

void update(int left, int right, int node, int target) {
    if (target < left || right < target) {
        return;
    }

    if (left == right) {
        if (left == target) {
            tree[node] = arr[target];
        }
    } else {
        int mid = (left + right) / 2;
        update(left, mid, node * 2, target);
        update(mid + 1, right, node * 2 + 1, target);
        tree[node] = compare(tree[node * 2], tree[node * 2 + 1]);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    tree.resize(n * 4);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    cin >> m;

    init(1, n, 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            arr[b].first = c;
            update(1, n, 1, b);
        } else {
            cout << tree[1].second << '\n';
        }
    }
}
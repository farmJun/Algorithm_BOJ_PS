#include "iostream"
#include "vector"

using namespace std;
int n, A, B, C;
long long S;
vector<long> tree;

int query(int left, int right, int node, int target) {
    if (left == right) {
        return left;
    } else {
        int mid = (left + right) / 2;
        if (tree[node * 2] >= target) {
            return query(left, mid, node * 2, target);
        } else {
            target -= tree[node * 2];
            return query(mid + 1, right, node * 2 + 1, target);
        }
    }
}

void update(int left, int right, int node, int target, long diff) {
    if (target < left || right < target) {
        return;
    } else {
        tree[node] += diff;
        if (left != right) {
            int mid = (left + right) / 2;
            update(left, mid, node * 2, target, diff);
            update(mid + 1, right, node * 2 + 1, target, diff);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    S = 1;
    while (S <= 1000000) {
        S *= 2;
    }
    cin >> n;
    tree.resize(S * 2);

    for (int i = 0; i < n; i++) {
        cin >> A;
        if (A == 1) {
            cin >> B;
            int target = query(1, S, 1, B);
            update(1, S, 1, target, -1);
            cout << target << "\n";
        } else {
            cin >> B >> C;
            update(1, S, 1, B, C);
        }
    }
}
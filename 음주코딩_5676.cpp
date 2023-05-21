#include "iostream"
#include "vector"
#include "cstring"

using namespace std;

int n, k, j, v;
char order;

vector<long long> arr;
vector<long long> tree;

long long init(int left, int right, int node) {
    if (left == right) {
        return tree[node] = arr[left];
    }

    int mid = (left + right) / 2;

    return tree[node] = init(left, mid, node * 2) * init(mid + 1, right, node * 2 + 1);
}

long long query(int left, int right, int node, int qLeft, int qRight) {
    if (qRight < left || right < qLeft) {
        return 1;
    } else if (qLeft <= left && right <= qRight) {
        return tree[node];
    } else {
        int mid = (left + right) / 2;

        return query(left, mid, node * 2, qLeft, qRight) * query(mid + 1, right, node * 2 + 1, qLeft, qRight);
    }
}

int update(int left, int right, int node, int target, long diff) {
    if (target < left || right < target) {
        return tree[node];
    } else if (left == right) {
        return tree[node] = diff;
    } else {
        int mid = (left + right) / 2;
        return tree[node] =
                       update(left, mid, node * 2, target, diff) * update(mid + 1, right, node * 2 + 1, target, diff);
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (true) {

        cin >> n >> k;

        if (cin.eof()) {
            break;
        }

        arr.resize(n + 1);
        tree.resize(4 * n + 1);

        for (int i = 1; i <= n; i++) {
            int num;
            cin >> num;

            if (num > 0) {
                arr[i] = 1;
            } else if (num < 0) {
                arr[i] = -1;
            } else {
                arr[i] = 0;
            }
        }

        init(1, n, 1);

        string answer = "";
        for (int i = 0; i < k; i++) {
            cin >> order >> v >> j;

            if (order == 'C') {
                if (j > 0) {
                    j = 1;
                } else if (j < 0) {
                    j = -1;
                } else {
                    j = 0;
                }
                update(1, n, 1, v, j);
            } else {
                int result = query(1, n, 1, v, j);
                if (result > 0) {
                    answer += "+";
                } else if (result < 0) {
                    answer += "-";
                } else {
                    answer += "0";
                }
            }
        }
        cout << answer << '\n';
    }
}
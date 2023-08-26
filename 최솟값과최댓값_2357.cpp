#include "iostream"
#include "vector"

using namespace std;

long long arr[1000001];
vector<long long> minTree;
vector<long long> maxTree;
int n, m;

long long initMin(int left, int right, int node) {
    if (left == right) {
        return minTree[node] = arr[left];
    }

    int mid = (left + right) / 2;
    return minTree[node] = min(initMin(left, mid, node * 2), initMin(mid + 1, right, node * 2 + 1));
}

long long initMax(int left, int right, int node) {
    if (left == right) {
        return maxTree[node] = arr[left];
    }

    int mid = (left + right) / 2;
    return maxTree[node] = max(initMax(left, mid, node * 2), initMax(mid + 1, right, node * 2 + 1));
}


long long queryMin(int left, int right, int node, int queryLeft, int queryRight) {
    if (queryRight < left || right < queryLeft) {
        return 2e9;
    } else if (queryLeft <= left && right <= queryRight) {
        return minTree[node];
    } else {
        int mid = (left + right) / 2;
        return min(queryMin(left, mid, node * 2, queryLeft, queryRight),
                   queryMin(mid + 1, right, node * 2 + 1, queryLeft, queryRight));
    }
}

long long queryMax(int left, int right, int node, int queryLeft, int queryRight) {
    if (queryRight < left || right < queryLeft) {
        return 0;
    } else if (queryLeft <= left && right <= queryRight) {
        return maxTree[node];
    } else {
        int mid = (left + right) / 2;
        return max(queryMax(left, mid, node * 2, queryLeft, queryRight),
                   queryMax(mid + 1, right, node * 2 + 1, queryLeft, queryRight));
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    minTree.resize(n * 4);
    maxTree.resize(n * 4);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    initMin(1, n, 1);
    initMax(1, n, 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << queryMin(1, n, 1, a, b) << ' ' << queryMax(1, n, 1, a, b) << '\n';
    }
}


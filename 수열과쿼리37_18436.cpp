#include "iostream"
#include "vector"

using namespace std;


int n, m;
long long arr[1000001];
vector<long long> evenTree;
vector<long long> oddTree;

long long initEven(int left, int right, int node) {
    if (left == right) {
        if (arr[left] % 2 == 0) {
            return evenTree[node] = 1;
        }
        return evenTree[node] = 0;
    }

    int mid = (left + right) / 2;
    return evenTree[node] = initEven(left, mid, node * 2) + initEven(mid + 1, right, node * 2 + 1);
}

long long initOdd(int left, int right, int node) {
    if (left == right) {
        if (arr[left] % 2 == 1) {
            return oddTree[node] = 1;
        }
        return oddTree[node] = 0;
    }

    int mid = (left + right) / 2;
    return oddTree[node] = initOdd(left, mid, node * 2) + initOdd(mid + 1, right, node * 2 + 1);
}

long long queryEven(int left, int right, int node, int qLeft, int qRight) {
    if (right < qLeft || qRight < left) {
        return 0;
    } else if (qLeft <= left && right <= qRight) {
        return evenTree[node];
    }

    int mid = (left + right) / 2;
    return queryEven(left, mid, node * 2, qLeft, qRight) + queryEven(mid + 1, right, node * 2 + 1, qLeft, qRight);
}

long long queryOdd(int left, int right, int node, int qLeft, int qRight) {
    if (right < qLeft || qRight < left) {
        return 0;
    } else if (qLeft <= left && right <= qRight) {
        return oddTree[node];
    }

    int mid = (left + right) / 2;
    return queryOdd(left, mid, node * 2, qLeft, qRight) + queryOdd(mid + 1, right, node * 2 + 1, qLeft, qRight);
}

void update(int left, int right, int node, int target) {
    if (target < left || right < target) {
        return;
    }


    if (left == right && left == target) {
        if (arr[target] % 2 == 0) { //짝
            if (evenTree[node] == 1) { // 짝
            } else { //홀
                evenTree[node] = 1;
                oddTree[node] = 0;
            }
        }

        if (arr[target] % 2 == 1) {
            if (oddTree[node] == 1) {
            } else {
                evenTree[node] = 0;
                oddTree[node] = 1;
            }
        }
        return;
    }

    int mid = (left + right) / 2;
    update(left, mid, node * 2, target);
    update(mid + 1, right, node * 2 + 1, target);

    oddTree[node] = oddTree[node * 2] + oddTree[node * 2 + 1];
    evenTree[node] = evenTree[node * 2] + evenTree[node * 2 + 1];
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    evenTree.resize(4 * n);
    oddTree.resize(4 * n);

    initEven(1, n, 1);
    initOdd(1, n, 1);

    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            arr[b] = c;
            update(1, n, 1, b);
        } else if (a == 2) {
            cout << queryEven(1, n, 1, b, c) << '\n';
        } else {
            cout << queryOdd(1, n, 1, b, c) << '\n';
        }
    }
}
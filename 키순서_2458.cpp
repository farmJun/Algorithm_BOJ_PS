#include "iostream"
#include "vector"
#include "cstring"

using namespace std;

int n, m, answer = 0;
bool visited[501];

vector<int> inDegree[501];
vector<int> outDegree[501];

int outPath(int x) {
    visited[x] = true;
    int count = 1;

    for (int next: outDegree[x]) {
        if (visited[next]) {
            continue;
        }
        count += outPath(next);
    }
    return count;
}

int inPath(int x) {
    visited[x] = true;
    int count = 1;

    for (int next: inDegree[x]) {
        if (visited[next]) {
            continue;
        }
        count += inPath(next);
    }
    return count;
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        outDegree[a].push_back(b);
        inDegree[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        int outCount = outPath(i) - 1;
        memset(visited, 0, sizeof(visited));
        int inCount = inPath(i) - 1;
        if (outCount + inCount == n - 1) {
            answer++;
        }
    }

    cout << answer;
}
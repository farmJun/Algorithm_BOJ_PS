#include "iostream"
#include "vector"
#include "queue"

using namespace std;

#define MAX 1001

vector<int> graph[MAX];
int inDegree[MAX];
int ans[MAX];
bool visited[MAX];
int n, m;

void bfs() {
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i: graph[cur]) {
            inDegree[i]--;
            if (inDegree[i] == 0) {
                ans[i] = max(ans[i], ans[cur] + 1);
                q.push(i);
            }
        }
    }
}

int main() {

    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        inDegree[b]++;
    }

    bfs();

    for (int i = 1; i <= n; i++) {
        cout << ans[i] + 1 << " ";
    }


}
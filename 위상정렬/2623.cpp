#include "iostream"
#include "vector"
#include "queue"

using namespace std;

#define MAX 1001

vector<int> graph[MAX];
vector<int> ans;
int inDegree[MAX];
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
        ans.push_back(cur);

        for (int i: graph[cur]) {
            inDegree[i]--;
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
    }
}

int main() {

    cin >> n >> m;

    while (m--) {
        vector<int> v;

        int t;
        cin >> t;

        while (t--) {
            int a;
            cin >> a;
            v.push_back(a);
        }

        for (int i = 0; i < v.size() - 1; i++) {
            graph[v[i]].push_back(v[i + 1]);
            inDegree[v[i + 1]]++;
        }
    }

    bfs();

    if (ans.size() == n) {
        for (int a: ans) {
            cout << a << "\n";
        }
    } else {
        cout << 0;
    }
}
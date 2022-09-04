#include "iostream"
#include "vector"
#include "queue"

using namespace std;

int n, k;

vector<int> graph[501];
int cost[501];
int ans[501];
int inDegree[501];

void bfs() {
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            ans[i] = cost[i];
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i: graph[cur]) {
            ans[i] = max(ans[i], ans[cur] + cost[i]);
            inDegree[i]--;
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
    }
}

int main() {

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;

        while (true) {
            int a;
            cin >> a;

            if (a == -1) {
                break;
            }
            graph[a].push_back(i);
            inDegree[i]++;
        }
        cost[i] = c;

    }

    bfs();


    for(int a : ans){
        if(a != 0){
            cout << a << "\n";
        }
    }

}
#include "iostream"
#include "queue"
#include "vector"


using namespace std;

int n;
vector<int> graph[501];
int inDegree[501];
int cost[501];
int answer[501];

void bfs() {

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            answer[i] = cost[i];
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i: graph[cur]) {

            answer[i] = max(answer[i], answer[cur] + cost[i]);

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
        cost[i] = c;

        int building;
        while (true) {
            cin >> building;
            if (building == -1) {
                break;
            }
            graph[building].push_back(i);
            inDegree[i]++;
        }
    }

    bfs();
    for (int i = 1; i <= n; i++) {
        cout << answer[i] << "\n";
    }

}
#include "iostream"
#include "vector"
#include "queue"

using namespace std;

#define MAX 32001

vector<int> graph[MAX];
int inDegree[MAX];
bool visited[MAX];
int n, m;

void bfs() {
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if(inDegree[i]==0){
            q.push(i);
        }
    }

    while (!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for(int i : graph[cur]){
            inDegree[i]--;
            if(inDegree[i]==0){
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
}
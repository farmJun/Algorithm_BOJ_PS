#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[1001];
vector<int>graph[10001];

void dfs(int x){
    cout << x << " ";
    visited[x] = true;
    for(int i:graph[x]){
        if(!visited[i]){
            dfs(i);
        }
    }
}

void bfs(int x){
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        if (visited[top]) {
            continue;
        }
        visited[top] = true;
        cout << top << " ";
        for (int i: graph[top]) {
            if (!visited[i]) {
                q.push(i);
            }
        }
    }
}

int main(){
    int n,m,v;
    cin >> n >> m >> v;

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        sort(graph[i].begin(),graph[i].end());
    }

    dfs(v);
    cout << endl;

    for (int i = 0; i <= n; i++) {
        visited[i] = false;
    }

    bfs(v);
}
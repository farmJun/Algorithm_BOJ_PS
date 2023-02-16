#include "iostream"
#include "vector"
#include "set"
#include "algorithm"

using namespace std;

int v, e;

vector<int> adj[10001];
int dist[10001];
int distCnt;
set<int> ans;

int dfs(int cur, bool isRoot) {
    dist[cur] = distCnt;
    distCnt++;

    int ret = dist[cur];
    int childCnt = 0;
    for (auto child: adj[cur]) {
        if (dist[child] != 0) {
            ret = min(ret, dist[child]);
        } else {
            childCnt++;
            int childTree = dfs(child, false);
            if (childTree >= dist[cur] && !isRoot) {
                ans.insert(cur);
            }
            ret = min(ret, childTree);
        }
    }

    if (isRoot && childCnt >= 2) {
        ans.insert(cur);
    }
    return ret;
}

int main() {
    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    distCnt = 1;

    for (int i = 1; i <= v; i++) {
        if (dist[i] == 0) {
            dfs(i, true);
        }
    }
    cout << ans.size() << "\n";
    for(int a : ans){
        cout << a << ' ';
    }

}
#include "iostream"
#include "vector"

using namespace std;

vector<int> graph[10001];
bool visited[10001];


int dfs(int x) {
    int cnt = 0;
    visited[x] = true;

    for (int i: graph[x]) {
        if (!visited[i]) {
            cnt++;
            cnt += dfs(i);
        }
    }
    return cnt;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }

    int maxNum = 0;
    vector<int>ans;

    for (int i = 1; i <= n; i++) {

        int cnt = dfs(i);

        if(cnt > maxNum){
            maxNum=cnt;
            ans.clear();
            ans.push_back(i);
        }
        else if(cnt ==maxNum){
            ans.push_back(i);
        }

        for (int j = 0; j <= n; j++) {
            visited[j] = false;
        }
    }

    for(int a : ans){
        cout << a << " ";
    }


}
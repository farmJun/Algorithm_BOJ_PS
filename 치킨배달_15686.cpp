#include "iostream"
#include "vector"
#include "climits"
#include "algorithm"
using namespace std;

int city[51][51];
vector<pair<int, int>> home;
int minNum = INT_MAX;

void distance(vector<pair<int, int>> chicken) {

    int chickDist = 0;

    for (int i = 0; i < home.size(); i++) {
        int nowDist = INT_MAX;

        for (int j = 0; j < chicken.size(); j++) {
            int dist = abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second);

            if (dist < nowDist) {
                nowDist = dist;
            }
        }
        chickDist += nowDist;
    }
    if (chickDist < minNum) {
        minNum = chickDist;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> chicken;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a;
            cin >> a;
            if (a == 1) {
                home.push_back({i, j});
            }
            if (a == 2) {
                chicken.push_back({i, j});
            }
        }
    }

    vector<bool> visited(chicken.size(), true);

    for (int i = 0; i < chicken.size() - m; i++) {
        visited[i] = false;
    }

    do {
        vector<pair<int, int>> temp;

        for (int i = 0; i < chicken.size(); i++) {
            if (visited[i]) {
                temp.push_back({chicken[i].first, chicken[i].second});
            }
        }
        distance(temp);
    } while (next_permutation(visited.begin(), visited.end()));

    cout << minNum;

}
#include "iostream"
#include "vector"

using namespace std;


int n, k;
int depth[100001];
int parent[100001][18];
pair<int, int> value[100001][18];
vector<pair<int, int>> arr[100001];

void makeTree(int cur) {
    for (auto child: arr[cur]) {
        int town = child.first;
        int base = child.second;

        if (depth[town] != 0) {
            continue;
        }

        depth[town] = depth[cur] + 1;
        parent[town][0] = cur;
        value[town][0] = make_pair(base, base);
        makeTree(town);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a].push_back({b, c});
        arr[b].push_back({a, c});
    }

    depth[1] = 1;
    makeTree(1);

    for (int k = 0; k <= 17; k++) {
        for (int i = 2; i <= n; i++) {
            int father = parent[i][k];
            if (father) {
                parent[i][k + 1] = parent[father][k];
                value[i][k + 1].first = min(value[i][k].first, value[father][k].first);
                value[i][k + 1].second = max(value[i][k].second, value[father][k].second);
            }
        }
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        int minV = 1000001;
        int maxV = -1;

        if (depth[a] < depth[b]) {
            swap(a, b);
        }

        int diff = depth[a] - depth[b];
        int cnt = 0;
        while (diff) {
            if (diff % 2 == 1) {
                minV = min(minV, value[a][cnt].first);
                maxV = max(maxV, value[a][cnt].second);
                a = parent[a][cnt];
            }
            diff /= 2;
            cnt++;
        }

        if (a != b) {
            for (int k = 17; k >= 0; k--) {
                if (parent[a][k] != parent[b][k]) {

                    minV = min(minV, value[a][k].first);
                    maxV = max(maxV, value[a][k].second);
                    a = parent[a][k];

                    minV = min(minV, value[b][k].first);
                    maxV = max(maxV, value[b][k].second);
                    b = parent[b][k];
                }
            }

            minV = min(minV, value[a][0].first);
            minV = min(minV, value[b][0].first);

            maxV = max(maxV, value[a][0].second);
            maxV = max(maxV, value[b][0].second);

            a = parent[a][0];
        }
        cout << minV << " " << maxV << "\n";
    }
}
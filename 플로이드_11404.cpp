#include "iostream"
#include "vector"

using namespace std;

int dist[101][101];

int n, m, a, b, c;


int main() {

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = 123456789;
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || dist[i][j] == 123456789){
                cout << 0 << ' ';
            }else{
                cout << dist[i][j] << ' ';
            }
        }
        cout << "\n";
    }
}

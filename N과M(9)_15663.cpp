#include "iostream"
#include "vector"
#include "set"
#include "algorithm"

using namespace std;

set<vector<int>> s;

int N, M;
int number[9];
bool visited[9];

void solve(vector<int> v, int count) {
    if (count == M) {
        s.insert(v);
        return;
    }

    int last = 0;

    for (int i = 0; i < N; i++) {
        if (visited[i] && number[i] == last) {
            continue;
        }

        visited[i] = true;
        last = number[i];
        v.push_back(number[i]);
        solve(v, count + 1);
        v.erase(v.begin());
        visited[i] = false;
    }
}


int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> number[i];
    }

    sort(number, number + N);

    vector<int> temp;
    solve(temp, 0);

    for (auto a: s) {
        for (int a2: a) {
            cout << a2 << " ";
        }
        cout << endl;
    }
}



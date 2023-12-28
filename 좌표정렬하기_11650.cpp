#include "iostream"
#include "vector"

using namespace std;


bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;

}

int main() {
    int n;
    cin >> n;

    vector <pair<int, int>> num;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        num.push_back(pair<int, int>(x, y));
    }

    sort(num.begin(), num.end(), compare);

    for (auto a: num) {
        cout << a.first << " " << a.second << "\n";
    }

}


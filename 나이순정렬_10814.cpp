#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector <pair<int, string>> v;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        string s;
        cin >> a >> s;
        v.push_back(pair<int, string>(a, s));
    }

    stable_sort(v.begin(), v.end(), compare);

    for (auto i: v) {
        cout << i.first << " " << i.second << "\n";
    }


}
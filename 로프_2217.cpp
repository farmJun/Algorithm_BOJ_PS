#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> rope;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        rope.push_back(w);
    }

    sort(rope.begin(), rope.end(), greater<int>());
    int max = 0;
    for (int i = 0; i < rope.size(); i++) {
        if (rope[i] * (i + 1) > max) {
            max = rope[i] * (i + 1);
        }
    }
    cout << max;

}
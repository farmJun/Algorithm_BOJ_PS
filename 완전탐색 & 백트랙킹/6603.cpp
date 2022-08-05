#include "iostream"
#include "vector"

using namespace std;

void combination(vector<int> arr, vector<int> comb, int r, int index, int depth) {
    if (r == 0) {
        for (int i = 0; i < comb.size(); i++) {
            cout << comb[i] << " ";
        }
        cout << "\n";
    } else if (depth == arr.size()) {
        return;
    } else {
        comb[index] = arr[depth];
        combination(arr, comb, r - 1, index + 1, depth + 1);
        combination(arr, comb, r, index, depth + 1);
    }
}


int main() {
    int n;

    while (true) {
        cin >> n;

        if (n == 0) {
            break;
        }
        vector<int> arr;
        vector<int> comb(6);

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            arr.push_back(a);
        }

        combination(arr, comb, 6, 0, 0);
        cout << "\n";
    }
}
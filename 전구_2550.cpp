#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

vector<int> arr;
vector<int> idx;
vector <vector<int>> ans;

int n;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        idx.push_back(a);
    }


    for (int i = 0; i < n; i++) {
        vector<int> temp;
        int index = find(idx.begin(), idx.end(), arr[i]) - idx.begin();
        cout << "index = " << index << '\n';
        temp.push_back(index);

        for (int j = i; j < n; j++) {
            if (i == j) {
                continue;
            }

            int insertIndex = find(idx.begin(), idx.end(), arr[j]) - idx.begin();

            if (temp.back() < insertIndex) {
                temp.push_back(insertIndex);
                cout << "insertIndex = " << insertIndex << '\n';

            }
        }
        for (int b: temp) {
            cout << b << ' ';
        }
        cout << '\n';

        ans.push_back(temp);
    }


    for (vector<int> a: ans) {
        for (int b: a) {
            cout << arr[b] << ' ';
        }
        cout << '\n';
    }
}
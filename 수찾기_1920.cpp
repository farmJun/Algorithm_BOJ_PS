#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

int N, M;
vector<int> A;
vector<int> mNumber;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end());

    cin >> M;
    for (int i = 0; i < M; i++) {
        int m;
        cin >> m;
        mNumber.push_back(m);
    }


    for (int i = 0; i < M; i++) {
        if (binary_search(A.begin(), A.end(), mNumber[i])) {
            cout << 1;
        } else {
            cout << 0;
        }
        cout << "\n";
    }
}
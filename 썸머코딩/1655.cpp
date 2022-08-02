#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v;
    priority_queue<int> v2;


    for (int i = 0; i < n; i++) {
        int A;
        cin >> A;
        v.push_back(A);
        v2.push(A);
        if (v2.size() % 2 != 0) {
            if (v2.size() == 1) {
                cout << v2.top() << "\n";
            } else {
                priority_queue<int> v3;

                for (int j = 0; j < v2.size() / 2; j++) {
                    v3.push(v2.top());
                    v2.pop();
                }

                cout << v2.top() << "\n";

                while (!v2.empty()) {
                    v3.push(v2.top());
                    v2.pop();
                }


            }


        } else {
            int a = v[v.size() / 2];
            int b = v[v.size() / 2 - 1];
            int c = a < b ? a : b;
            cout << c << "\n";
        }
    }
}

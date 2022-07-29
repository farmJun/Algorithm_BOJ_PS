#include "iostream"
#include "stack"
#include "vector"

using namespace std;

int main() {
    vector<pair<int, int>> homework;

    int n;
    char order;
    int total = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> order;

        if (order == '1') {
            int a, b;
            cin >> a >> b;

            if (b - 1 == 0) {
                total += a;
            } else {
                homework.push_back(pair<int, int>(a, b - 1));
            }
        } else {
            if(!homework.empty()){
                homework.back().second--;
            }

            if (!homework.empty() && homework.back().second <= 0) {
                total += homework.back().first;
                homework.erase(homework.end() - 1);
            }
        }
    }
    cout << total;

}
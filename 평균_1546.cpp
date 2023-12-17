#include "iostream"
#include "vector"

using namespace std;

int main() {
    int n;
    cin >> n;
    int max = 0;
    vector<double> score;
    for (int i = 0; i < n; i++) {
        double a;
        cin >> a;
        if (a > max) {
            max = a;
        }
        score.push_back(a);
    }

    for (int i = 0; i < score.size(); i++) {
        score[i] = score[i] / max * 100;
    }
    double total = 0;
    for (int i = 0; i < score.size(); i++) {
        total += score[i];
    }
    cout << total / score.size();
}

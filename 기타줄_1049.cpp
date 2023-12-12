#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int sixline[50];
int oneline[50];

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {

        cin >> sixline[i] >> oneline[i];
    }

    sort(sixline, sixline + M);
    sort(oneline, oneline + M);

    int sum = 0;
    int line = N;

    while (line > 0) {

        if (line >= 6) {
            if (sixline[0] > oneline[0] * 6) {
                sum += oneline[0] * line;
                line -= line;
            } else {
                sum += sixline[0];
                line -= 6;
            }
        } else {
            if (sixline[0] < oneline[0] * line) {
                sum += sixline[0];
                line -= 6;
            } else {
                sum += oneline[0] * line;
                line -= line;
            }
        }
    }

    cout << sum << "\n";
    return 0;
}
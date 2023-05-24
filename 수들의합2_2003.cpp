#include "iostream"
#include "vector"

using namespace std;

int N, M;
vector<int> input;

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        input.push_back(a);
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = i; j < N; j++) {
            sum += input[j];

            if (sum == M) {
                count++;
            }
        }
    }

    cout << count;
}
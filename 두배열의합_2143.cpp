#include "iostream"
#include "vector"

using namespace std;

int N, M, T;
vector<long> inputA;
vector<long> inputB;

vector<long> subA;
vector<long> subB;

bool compare(int a, int b) {
    return a > b;
}

int main() {
    cin >> T;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        inputA.push_back(a);
    }

    cin >> M;

    for (int i = 0; i < M; i++) {
        int b;
        cin >> b;
        inputB.push_back(b);
    }

    //long sum = 0;
    /* for (int i = 0; i < N; i++) {
         sum = inputA[i];
         subA.push_back(sum);

         for (int j = i + 1; j < N; j++) {
             sum += inputA[j];
             subA.push_back(sum);
         }
     }*/
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = i; j < N; j++) {
            sum += inputA[j];
            subA.push_back(sum);
        }
    }

    /*for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = i + 1; j < N; j++) {
            sum += inputA[j];
            subA.push_back(sum);
        }
    }
*/
    for (int i = 0; i < M; i++) {
        int sum = inputB[i];
        subB.push_back(sum);
        for (int j = i + 1; j < M; j++) {
            sum += inputB[j];
            subB.push_back(sum);
        }
    }

    sort(subA.begin(), subA.end());
    sort(subB.begin(), subB.end(), compare);

    for (long a: subA) {
        cout << a << " ";
    }
    cout << endl;


    for (long a: subB) {
        cout << a << " ";
    }
    cout << endl;
    long result = 0;
    int ptA = 0;
    int ptB = 0;
    long sum;
    while (true) {
        long curA = subA[ptA];
        long curB = subB[ptB];
        sum = curA + curB;
        if (sum == T) {
            long countA = 0;
            while (ptA < subA.size() && curA == subA[ptA]) {
                countA++;
                ptA++;
            }

            long countB = 0;
            while (ptB < subB.size() && curB == subB[ptB]) {
                countB++;
                ptB++;
            }

            result += countA * countB;
        } else if (sum < T) {
            ptA++;
        } else {
            ptB++;
        }


        if (ptA == subA.size() || ptB == subB.size()) {
            break;
        }

    }
    cout << result;
}
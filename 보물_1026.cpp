#include<iostream>

using namespace std;

int num;
const int Max = 50;

int arrayA[Max];
int arrayB[Max];


bool solve(int a, int b) {
    return a > b;
}

int main() {
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> arrayA[i];
    }

    for (int i = 0; i < num; i++) {
        cin >> arrayB[i];
    }

    sort(arrayA, arrayA + num);
    sort(arrayB, arrayB + num, solve);

    int total = 0;
    for (int i = 0; i < num; i++) {
        total += arrayA[i] * arrayB[i];
    }

    cout << total;
}
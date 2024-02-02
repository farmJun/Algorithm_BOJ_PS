#include "iostream"
#include "algorithm"

using namespace std;
string input;
int arr[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> input;
    for (int i = 0; i < input.length(); i++) arr[input[i] - '0']++;
    arr[6] = ((arr[9] + arr[6]) % 2 == 0) ? (arr[9] + arr[6]) / 2 : (arr[9] + arr[6]) / 2 + 1;
    sort(arr, arr + 9, greater<int>());
    cout << arr[0];
}
#include <iostream>
#include<vector>

using namespace std;

int main() {
    int leak, tape;
    cin >> leak >> tape;
    vector<int> spot;
    for (int i = 0; i < leak; i++) {
        int a;
        cin >> a;
        spot.push_back(a);
    }
    sort(spot.begin(), spot.end());
    int cnt = 1;
    int start = spot[0];
    for (int i = 1; i < leak; i++) {
        if ((spot[i] - start) > (tape - 1)) {
            cnt++;
            start = spot[i];
        }
    }
    cout << cnt;
}
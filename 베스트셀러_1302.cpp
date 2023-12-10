#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string, int> a, pair<string, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }

    return a.second > b.second;
}


int main() {
    vector <pair<string, int>> book;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string b;
        cin >> b;
        vector < pair < string, int >> ::iterator iter;
        bool contain = false;

        for (iter = book.begin(); iter != book.end(); iter++) {
            if (iter->first == b) {
                iter->second++;
                contain = true;
                break;
            }
        }
        if (!contain) {
            book.push_back(pair<string, int>(b, 1));
        }
    }
    sort(book.begin(), book.end(), compare);

    cout << book.begin()->first;
}
#include <iostream>
#include <vector>

using namespace std;


vector <pair<int, int>> balloon;

void moveRight(int a) {
    for (int i = 0; i < a - 1; i++) {
        balloon.push_back(balloon.front());
        balloon.erase(balloon.begin());
    }
}

void moveLeft(int a) {
    a = -a;
    for (int i = 0; i < a; i++) {
        balloon.insert(balloon.begin(), balloon.back());
        balloon.erase(balloon.end() - 1);
    }
}


int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        balloon.push_back(pair<int, int>(i + 1, a));

    }

    for (int i = 0; i < n; i++) {
        cout << balloon.front().first << " ";
        int index = balloon.front().second;
        balloon.erase(balloon.begin());

        if (index > 0) {
            moveRight(index);
        } else {
            moveLeft(index);
        }
    }
}
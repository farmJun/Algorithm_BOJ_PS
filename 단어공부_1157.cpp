#include "iostream"

using namespace std;

int alpha[26];

int main() {

    string word;
    cin >> word;


    for (int i = 0; i < word.length(); i++) {
        if (word[i] < 97) {
            alpha[word[i] - 65]++;
        } else {
            alpha[word[i] - 97]++;
        }
    }
    int max = 0;
    int index = 0;

    for (int i = 0; i < 26; i++) {
        if (max < alpha[i]) {
            max = alpha[i];
            index = i;
        }
    }

    int cnt = 0;

    for (int i = 0; i < 26; i++) {
        if (alpha[i] == max) {
            cnt++;
        }
    }

    if (cnt > 1) {
        cout << "?";
    } else {
        cout << (char) (index + 65);
    }
}

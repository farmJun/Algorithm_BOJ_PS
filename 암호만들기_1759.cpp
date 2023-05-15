#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

/*
 * 1. 체크인
 * 2. 목적지인가?
 * 3. 연결된 곳을 순회
 * 4. 갈 수 있는가?
 * 5. 간다
 * 6. 체크아웃
 */

int L, C;

vector<char> words;

bool isConsonants(char c) {
    return (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u');
}

bool isVowels(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void dfs(int start, int vowelsCount, int consonantsCount, string password) {
    password += words[start];

    if (isVowels(words[start])) {
        vowelsCount++;
    }

    if (isConsonants(words[start])) {
        consonantsCount++;
    }

    if (password.length() == L && vowelsCount >= 1 && consonantsCount >= 2) {
        cout << password << "\n";
        return;
    }

    for (int i = start + 1; i < C; i++) {
        dfs(i, vowelsCount, consonantsCount, password);
    }
}

int main() {

    cin >> L >> C;
    for (int i = 0; i < C; i++) {
        char word;
        cin >> word;
        words.push_back(word);
    }

    sort(words.begin(), words.end());

    for (int i = 0; i <= C - L; i++) {
        dfs(i, 0, 0, "");
    }
}
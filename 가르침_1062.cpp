#include "iostream"
#include "vector"

using namespace std;

/*
 * 1. 체크인 : 가르쳤다.
 * 2. 목적지인가? : 가르칠 수 있는 남은 글자의 개수가 있는가? -> 읽을 수 있는 단어 카운트
 * 3. 연결된 곳 순회 : A ~ Z -> 나보다 뒤 ~ Z
 * 4. 갈 수 있는가? : 가르친 적이 없음
 * 5. 간다 : DFS 호출
 * 6. 체크아웃 : 가르침 X
 */

int N, K, result;
vector<string> words;
bool alphabet[26];

int calculate() {

    bool canRead;
    int count = 0;

    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        canRead = true;
        for (int j = 0; j < word.length(); j++) {
            char character = word[j];
            if (!alphabet[character - 'a']) {
                canRead = false;
                break;
            }
        }

        if (canRead) {
            count++;
        }
    }

    return count;
}

void dfs(int start, int count) {

    if (count == K) {
        result = max(result, calculate());
        return;
    }

    for (int i = start; i < 26; i++) {
        if (alphabet[i]) {
            continue;
        }
        alphabet[i] = true;
        dfs(i, count + 1);
        alphabet[i] = false;
    }
}

void input() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }
}

void init() {
    if (K < 5) {
        cout << 0;
        exit(0);
    } else if (K == 26) {
        cout << N;
        exit(0);
    }

    alphabet['a' - 'a'] = true;
    alphabet['n' - 'a'] = true;
    alphabet['t' - 'a'] = true;
    alphabet['i' - 'a'] = true;
    alphabet['c' - 'a'] = true;
    K -= 5;
}

int main() {
    input();
    init();
    dfs(0, 0);
    cout << result;
}
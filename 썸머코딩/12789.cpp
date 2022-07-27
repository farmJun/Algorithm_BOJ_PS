#include "iostream"
#include "stack"
#include "vector"
#include "queue"

using namespace std;

int main() {

    stack<int> waiting;
    queue<int> student;
    vector<int> after;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        student.push(a);
    }

    int now = 1;

    while (!student.empty()) {
        if (student.front() == now) {
            after.push_back(now);
            now++;
            student.pop();
        } else if (!waiting.empty() && waiting.top() == now) {
            waiting.pop();
            after.push_back(now);
            now++;
        } else {
            waiting.push(student.front());
            student.pop();
        }
    }


    while (!waiting.empty()) {
        after.push_back(waiting.top());
        waiting.pop();
    }

    bool possible = true;

    for (int i = 0; i < after.size() - 1; i++) {
        if (after[i] > after[i + 1]) {
            possible = false;
            break;
        }
    }



}
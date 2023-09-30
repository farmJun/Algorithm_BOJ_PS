#include "iostream"
#include "deque"
#include "algorithm"

using namespace std;

int n;
deque<int> temp;
deque<int> diff;

void diffMax() {

    if (diff.size() == n) {
        return;
    }

    if (diff.empty()) {
        diff.push_back(temp.front());
        temp.pop_front();
        diffMax();
        return;
    }

    int f = max(abs(diff.front() - temp.front()), abs(diff.front() - temp.back()));
    int b = max(abs(diff.back() - temp.front()), abs(diff.back() - temp.back()));

    if (f > b) {
        if (abs(diff.front() - temp.front()) > abs(diff.front() - temp.back())) {
            diff.push_front(temp.front());
            temp.pop_front();
        } else {
            diff.push_front(temp.back());
            temp.pop_back();
        }

    } else {
        if (abs(diff.back() - temp.front()) > abs(diff.back() - temp.back())) {
            diff.push_back(temp.front());
            temp.pop_front();
        } else {
            diff.push_back(temp.back());
            temp.pop_back();
        }
    }

    diffMax();

}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        temp.push_back(a);
    }
    sort(temp.begin(), temp.end());

    diffMax();

    int total = 0;

    for (int i = 0; i < diff.size() - 1; i++) {
        total += abs(diff[i] - diff[i + 1]);
    }
    cout << total;
}
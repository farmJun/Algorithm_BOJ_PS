#include "iostream"
#include "deque"
#include "algorithm"

using namespace std;

int N, K, number;

struct Node {
    int number;
    int count;
    int time;

    Node(int number, int count, int time) {
        this->number = number;
        this->count = count;
        this->time = time;
    }
};


deque<Node> pictures;

bool compare(Node n1, Node n2) {

    if (n1.count == n2.count) {
        return n1.time > n2.time;
    }

    return n1.count < n2.count;
}

int main() {
    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        cin >> number;

        bool isContain = false;

        for (Node &picture: pictures) {
            if (picture.number == number) {
                isContain = true;
                picture.count++;
                break;
            }
        }
        // count에 대해 내림차순 정렬
        // count 같으면 time으로 내림차순 정렬


        if (!isContain && pictures.size() == N) {
            cout << "before sort ";
            for (Node &picture: pictures) {
                cout << picture.number << " ";
            }
            cout << endl;

            sort(pictures.begin(), pictures.end(), compare);

            cout << "after sort ";

            for (Node &picture: pictures) {
                cout << picture.number << " ";
            }
            cout << endl;

            pictures.pop_front();
            pictures.push_front(Node{number, 0, 0});
        } else {
            pictures.push_back(Node{number, 0, 0});
        }

        for (Node &picture: pictures) {
            cout << picture.number << " ";
        }
        cout << endl;
    }

    for (Node &picture: pictures) {
        cout << picture.number << " ";
    }

}


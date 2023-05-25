#include "iostream"
#include "vector"

using namespace std;

int N;

class minHeap {
public:
    vector<int> heap = {0};

    void insert(int val) {
        heap.push_back(val);
        int cur = heap.size();
        int par = cur / 2;

        while (true) {
            if (par == 0 || heap[par] <= heap[cur]) {
                break;
            }

            int temp = heap[par];
            heap[par] = heap[cur];
            heap[cur] = temp;

            cur = par;
            par = cur / 2;
        }
    }

    int remove() {
        int root = heap[1];
        heap[1] = heap[heap.size() - 1];
        heap.pop_back();

        int curPos = 1;
        while (true) {
            int left = curPos * 2;
            int right = curPos * 2 + 1;

            if (left >= heap.size()) {
                break;
            }

            int min = heap[left];
            int minPos = left;

            if (right < heap.size() && min > heap[right]) {
                min = heap[right];
                minPos = right;
            }

            if (heap[curPos] > min) {
                int temp = heap[curPos];
                heap[curPos] = heap[minPos];
                heap[minPos] = temp;
                curPos = minPos;
            } else {
                break;
            }
        }

        return root;
    }

    bool isEmpty() {
        return heap.size() == 1;
    }
};


int main() {

    minHeap min;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a == 0) {
            if (min.isEmpty()) {
                cout << 0 << "\n";
            } else {
                cout << min.remove() << "\n";
            }
        } else {
            min.insert(a);
        }
    }
}
#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;

class Jewel {

private:
    int weight;
    int value;

public:
    Jewel(int weight, int value) : weight(weight), value(value) {
    }

    int getWeight() const {
        return weight;
    }

    void setWeight(int weight) {
        Jewel::weight = weight;
    }

    int getValue() const {
        return value;
    }

    void setValue(int value) {
        Jewel::value = value;
    }
};

bool compare(Jewel a, Jewel b) {
    return a.getValue() > b.getValue();
}


vector<int> bag;
vector<Jewel> jewels;

int main() {

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        Jewel jewel = Jewel(a, b);
        jewels.push_back(jewel);
    }

    for (int i = 0; i < K; i++) {
        int a;
        cin >> a;
        bag.push_back(a);
    }

    sort(bag.begin(), bag.end());

    //sort(jewels.begin(), jewels.end(), compare);

    priority_queue<Jewel*> pq;

    long result = 0;
    int jIdx = 0;
    for (int i = 0; i < bag.size(); i++) {
        while (jIdx < N && jewels[jIdx].getWeight() <= bag[i]) {
            pq.push(jewels[jIdx]);
        }

        if(pq.empty()){
            result += pq.top().getValue();
            pq.pop();
        }
    }

}

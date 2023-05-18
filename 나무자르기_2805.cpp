#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int N, M;
vector<int> trees;

int main() {
    cin >> N >> M;


    for (int i = 0; i < N; i++) {
        int tree;
        cin >> tree;
        trees.push_back(tree);
    }

    int highCut = *max_element(trees.begin(), trees.end());
    int lowCut = 0;
    int midCut;

    int result = 0;
    while (lowCut <= highCut) {
        midCut = (highCut + lowCut) / 2;
        long long int sum = 0;

        for (int tree: trees) {
            if (tree - midCut > 0) {
                sum += tree - midCut;
            }
        }

        if (sum < M) {
            highCut = midCut - 1;
        } else {
            result = midCut;
            lowCut = midCut + 1;
        }
    }

    cout << result;
}
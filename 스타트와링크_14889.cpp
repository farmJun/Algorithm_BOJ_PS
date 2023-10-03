#include "iostream"
#include<vector>
#include<algorithm>

using namespace std;

int n;
int arr[20 + 1][20 + 1];
int minNum = 10001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int k = n / 2;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    vector<int> v;

    for (int i = 1; i <= n; i++) {
        v.push_back(i);
    }

    vector<int> temp;

    for (int i = 0; i < k; i++) {
        temp.push_back(1);
    }

    for (int i = 0; i < v.size() - k; i++) {
        temp.push_back(0);
    }

    sort(temp.begin(), temp.end());

    int cnt = 0;

    do {
        vector<int> start;
        vector<int> link;
        int startTotal = 0;
        int linkTotal = 0;

        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] == 1) {
                start.push_back(v[i]);
            } else {
                link.push_back(v[i]);
            }
        }

        for (int i = 0; i < start.size(); i++) {
            for (int j = i + 1; j < start.size(); j++) {
                startTotal += arr[start[i]][start[j]];
                startTotal += arr[start[j]][start[i]];
            }
        }

        for (int i = 0; i < link.size(); i++) {
            for (int j = i + 1; j < link.size(); j++) {
                linkTotal += arr[link[i]][link[j]];
                linkTotal += arr[link[j]][link[i]];
            }
        }

        int diff = abs(linkTotal - startTotal);
        if(diff < minNum){
            minNum = diff;
        }
        if(minNum==0){
            break;
        }

    } while (next_permutation(temp.begin(), temp.end()));

    cout << minNum;
}
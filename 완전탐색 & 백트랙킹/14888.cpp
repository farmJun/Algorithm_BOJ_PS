#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

vector<int> num;
vector<int> oper;
vector<int> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        num.push_back(a);
    }

    for (int i = 0; i < 4; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++) {
            oper.push_back(i);
        }
    }

    sort(oper.begin(), oper.end());

    do {

        int total = num[0];

        for (int i = 0; i < oper.size() + 1; i++) {
            switch (oper[i]) {
                case 0:
                    total += num[i + 1];
                    break;
                case 1:
                    total -= num[i + 1];
                    break;
                case 2:
                    total *= num[i + 1];
                    break;
                case 3:
                    total /= num[i + 1];
                    break;
            }
        }
        ans.push_back(total);

    } while (next_permutation(oper.begin(), oper.end()));


    sort(ans.begin(), ans.end());

    cout << ans.back() << "\n" << ans.front();
}
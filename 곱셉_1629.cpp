#include <iostream>

using namespace std;
typedef long long ll;
int a, b, c;

ll solve(int a, int b, int c) {
    if (b == 1) {
        return (a * b) % c;
    }
    ll half = solve(a, b / 2, c);

    if (b % 2) {
        return ((half * half % c) * a) % c;
    }else{
        return (half * half) % c;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> a >> b >> c;
    cout << solve(a, b, c);
}

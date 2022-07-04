#include <iostream>
using namespace std;

int main(){
    int a;
    cin >> a;
    int cnt =0;
    while (a>=0){
        if(a%5==0){
            cnt += a/5;
            cout << cnt;
            return 0;
        }

        a-=3;
        cnt++;

    }
    cout << -1 ;
}
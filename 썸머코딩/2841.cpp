#include <iostream>
#include <stack>
using namespace std;

int main(){
    int cnt=0;
    int N, P;
    cin>> N >> P;
    stack<int>guitar[6];

    for(int i=0; i < N; i++){
        int line, plat;
        cin >> line >> plat;

        if(guitar[line-1].empty()){
            guitar[line-1].push(plat);
            cnt++;
        }
        else if (guitar[line-1].top() <plat){
                cnt ++;
                guitar[line-1].push(plat);
        }
        else  if(guitar[line-1].top() == plat ){
            continue;
        }
        else if(guitar[line-1].top() > plat){
            while(!guitar[line-1].empty() && guitar[line-1].top() > plat){
                guitar[line-1].pop();
                cnt ++;
            }

            if(!guitar[line-1].empty() && guitar[line-1].top() == plat ){
                continue;
            }
            else{
                guitar[line-1].push(plat);
                cnt++;
            }
        }
    }
    cout << cnt;
}


#include <iostream>
#include <map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<string,string> list;
    int n, m;
    cin >> n>>m;
    for(int i=0;i<n;i++){
        string site, pw;
        cin >> site >> pw;
        list[site] =pw;
    }
    for(int i=0;i<m;i++){
        string site;
        cin >> site;
        cout << list[site] <<"\n";
    }
}
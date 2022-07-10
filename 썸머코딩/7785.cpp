#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b){
    return a>b;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<string, bool> people;
    vector<string> enterPeople;
    int n;
    cin >> n;

    for(int i=0; i<n;i++){
        string name, enter;
        cin >> name >> enter;
        if(enter=="enter"){
            people[name]= true;
        }
        else if(enter =="leave"){
           people[name]= false;
        }
    }

    for(auto iter = people.begin() ; iter != people.end(); iter++){
        if(iter->second){
           enterPeople.push_back(iter->first);
        }
    }
    sort(enterPeople.begin(), enterPeople.end(), compare);
    for(string name : enterPeople){
        cout << name << "\n";
    }

}


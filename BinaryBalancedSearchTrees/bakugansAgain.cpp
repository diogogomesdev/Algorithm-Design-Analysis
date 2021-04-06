#include <iostream>
#include <set>
#include <iterator>

using namespace std;

int main(){

    int A, R, energy;
    multiset <int> ms;
    multiset <int> :: iterator itr;
    string op;
    int array[100000], pos=0;

    cin >> A >> R;

    for(int i=0; i<(A+R);i++){
        cin >> op;
        if(op == "BAK"){
            cin >> energy;
            ms.insert(energy);
        }
        else if(op == "MIN"){
            itr = ms.begin();
            array[pos] = *itr;
            pos++;
            ms.erase(itr);
        }
        else{
            itr = ms.end();
            itr--;
            array[pos] = *itr;
            pos++;
            ms.erase(itr);
        }
    }

    for(int j=0;j<pos;j++){
            cout << array[j] << endl;
    }

    return 0;
}

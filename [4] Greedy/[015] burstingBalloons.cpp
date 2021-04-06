#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, balon, sum=1, flechas[100000], counter=1;
    bool find = false;

    cin >> n;
    
    cin >> balon;
    flechas[0] = balon - 1;
    for(int i=1;i<n;i++){
        cin >> balon;
        for(int k=0;k<counter;k++){
            if(balon == flechas[k]){
                find = true;
                flechas[k] = balon-1;
                break;
            }
        }
        if(!find){
            flechas[counter] = balon-1;
            counter++;
            sum++;
        }
        else find = false;

    }

    cout << sum << endl;

    return 0;
}

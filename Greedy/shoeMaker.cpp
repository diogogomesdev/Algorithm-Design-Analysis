#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class encomenda{
    public:
        int pos;
        float duracao;
        float multa;
        float div;
};

bool compare(encomenda a, encomenda b){
    float adiv = a.duracao * b.multa;
    float bdiv = b.duracao*a.multa;
    if(a.div == b.div){
        if(adiv == bdiv) return(a.pos < b.pos);
        else return(adiv < bdiv);
    }
    return(a.div < b.div);
}

int main(){

    encomenda enc[1000];
    int n;

    cin >> n;

    for(int i=0;i<n;i++){
        cin >> enc[i].duracao >> enc[i].multa;
        enc[i].pos = i+1;
        enc[i].div = enc[i].duracao/enc[i].multa;
    }

    sort(enc, enc + n, compare);

    for(int i=0;i<n;i++){
        if(i==n-1) cout << enc[i].pos << endl;
        else cout << enc[i].pos << " ";
    }

    return 0;
}

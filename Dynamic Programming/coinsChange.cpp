#include <iostream>
#include <cstring>

using namespace std;

int tMoedas[100], perguntas[100];

class valor{
public:
	int qMoedas=0;
	int sum[100];
};

valor arr[10000];

void dinamic(int value, int n){
	int hold, min=10000, store_Ind_moeda, store_pos;
	for(int i=0;i<n;i++){
		if(value == tMoedas[i]){
			arr[value].qMoedas = 1;
			arr[value].sum[i] = 1;
			return;
		}
		else if(tMoedas[i] <= value){
			hold = arr[value-tMoedas[i]].qMoedas + 1;
			if(hold<min){
				min = hold;
				store_Ind_moeda = i;
				store_pos = value-tMoedas[i];
			}
		}
	}
	arr[value].qMoedas = min;
	memcpy(arr[value].sum,arr[store_pos].sum,sizeof(int)*100);
	arr[value].sum[store_Ind_moeda]++;
}


int main(){


	int n, p, max=0;

	cin >> n;

	for(int i=0;i<n;i++){
		cin >> tMoedas[i];
	}

	cin >> p;

	for(int i=0;i<p;i++){
		cin >> perguntas[i];
		if(perguntas[i]>max) max = perguntas[i];
	}	

	//corrigir valor | nao esquecer
	for(int i=1;i<=max;i++){
		dinamic(i, n);
	}

int SUM=0;
	//TESTE
	
	for(int i=0;i<p;i++){
		cout << perguntas[i] << ": [" << arr[perguntas[i]].qMoedas << "] ";
		for(int k=0;k<n;k++){
			if(arr[perguntas[i]].sum[k]>0){
				for(int j=0;j<arr[perguntas[i]].sum[k];j++){
					SUM += tMoedas[k];
					if(SUM==perguntas[i]) cout << tMoedas[k] << endl;
					else cout << tMoedas[k] << " ";
				}
			}
		}
		SUM=0;
	}
	
	return 0;
}

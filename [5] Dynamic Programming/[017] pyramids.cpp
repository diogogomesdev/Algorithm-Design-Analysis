#include <iostream>

using namespace std;

int main(){

	int n, d, linha, coluna, numPedras=0;

	long long int arr[500500]; 
	int linhas[1000];

	cin >> n;

	for(int i=n;i>0;i--) numPedras += i;

	//guardar elemento inicial de cada linha num array
	int copy_n = n;
	linhas[0]=0;
	for(int i=1;i<=n;i++){
		linhas[i] = linhas[i-1] + copy_n;
		copy_n--;
	}

	//input pedras danificadas
	cin >> d;
	for(int i=0;i<d;i++){
		cin >> linha >> coluna;
		coluna--;
		arr[linhas[linha-1]+coluna] = -1;
	}

	//começo da solução || começar a primeira linha
	for(int i=0;i<n;i++){
		if(arr[i]==-1) arr[i] = 0;
		else arr[i] = 1;
	}

	copy_n = n-1;
	int n2 = n;
	//fazer iteração sobre todas as outras linhas
	for(int i=1;i<n;i++){
		for(int j=linhas[i];j<(linhas[i]+copy_n);j++){
			if(arr[j]==-1) arr[j]=0;
			else arr[j] = arr[j-(n2)] + arr[j-(n2-1)];
		}
		copy_n--;
		n2--;
	}

	//SOLUÇAO
	cout << arr[numPedras-1] << endl;

	return 0;
}

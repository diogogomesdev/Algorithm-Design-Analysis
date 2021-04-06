#include <iostream>

using namespace std;

int dist[1000], sum[1000];

int indirectBinarySearch(int parts, int size){
	int left = 1, right = sum[size];
	int min = 1000000;

	while(left<right){
		int middle = left + (right - left) / 2;

		//testar se posso fazer particoes em que o maximo é middle

		int soma = middle, teste=0;

		for(int i=0;i<=size;i++){
			if(sum[i]>soma){
				teste++;
				soma = sum[i-1] + middle;
			}

		}
		if(teste == parts-1){
			if(sum[size]<=soma){
				min = middle;
				right = middle;
			}
			else left = middle + 1;
		}
		else if(teste < parts){
			min = middle;
			right = middle;
		}
		else{
			left = middle + 1;
		}
	}
	return min;
}

int max(int size){
	int max =0;
	for(int i=0;i<=size;i++){
		if(dist[i]>max) max = dist[i];
	}
	return max;
}


int main(){

	int N, P, K, sol;

	//-------------- INPUT -------------

	cin >> N;
	cin >> dist[0];
	sum[0]=dist[0];
	for(int i=1;i<N;i++){
		cin >> dist[i];
		sum[i] += sum[i-1] + dist[i]; 
	}


	cin >> P;
	for(int i=0;i<P;i++){
		cin >> K;
		if(K==1) sol = sum[N-1];
		else if(K==N) sol = max(N-1);
		else{
			sol = indirectBinarySearch(K, N-1);
			if(sol<(max(N-1))) sol = max(N-1);
		}
		cout << sol << endl;
	}


	return 0;
}

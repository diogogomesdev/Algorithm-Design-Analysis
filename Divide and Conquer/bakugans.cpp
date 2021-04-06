#include <iostream>

using namespace std;

int main(){

	int n, numPhotos, cumSum=0, energy, min, max;

	cin >> n;

	int bak[n];

	for(int i=0;i<n;i++){
		cin >> energy;
		cumSum += energy;
		bak[i]=cumSum;
	}

	cin >> numPhotos;

	for(int i=0;i<numPhotos;i++){
		cin >> min >> max;
		if(min<2){
			cout << bak[max-1] << endl;
		}
		else cout << (bak[max-1]-bak[min-2]) << endl;
	}

	return 0;
}

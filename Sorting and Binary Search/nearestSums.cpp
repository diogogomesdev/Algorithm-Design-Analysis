#include <iostream>
#include <algorithm>

using namespace std;

int s[1000], sums[1000000];

void insertionSort(int size){
	for(int i=1;i<size;i++){
		int hold = sums[i];
		int j = i;
		while(j>0 && hold<sums[j-1]){
			sums[j]=sums[j-1];
			j--;
		}
		sums[j] = hold;
	}
}

int binarySearch(int value, int left, int right){
	int min = 4000;
	int toReturn = -1;
	while(left <= right){
		int middle = left + (right - left)/2;
		if(value == sums[middle]){
			return sums[middle];
		}
		else if(value < sums[middle]){
			if((sums[middle]-value) < min){
				min = sums[middle]-value;
				toReturn = sums[middle];
			}
			right = middle-1;
		}
		else if(value > sums[middle]){
			if(value-sums[middle] < min){
				min = value - sums[middle];
				toReturn = sums[middle];				
			}
			left = middle + 1;
		}
	}
	return toReturn;
}

int classicBinarySearch(int value, int left, int right){
	while(left<=right){
		int middle = left + (right - left)/2;
		if(value == sums[middle]) return 1;
		else if(value < sums[middle]) right = middle - 1;
		else left = middle + 1;
	}
	return -1;
}

int main(){

	int N, Q, p;

	cin >> N;

	for(int i=0;i<N;i++){
		cin >> s[i];
	}

	//Store sum of all pairs
	int k=0;
	for(int i=0;i<N-1;i++){
		for(int j=i+1;j<N;j++){
			sums[k] = s[i]+s[j];
			k++;
		}
	}

	//for(int i=1;i<N;i++) soma += i;

	//Sorting the array
	//insertionSort(k);

	sort(sums, sums+k);

	int sol2, dif, p2;

	cin >> Q;
	for(int i=0;i<Q;i++){
		cin >> p;
		if(p<sums[0]) cout << sums[0] << endl;
		else if(p>sums[k-1]) cout << sums[k-1] << endl;
		else{ 
			int sol = binarySearch(p, 0, k-1);
			if(sol == p) cout << p << endl;
			else{
				if(sol>p){
					dif = sol - p;
					p2 = p - dif;
				}
				else{
					dif = p - sol;
					p2 = p + dif;

				}
				sol2 = classicBinarySearch(p2, 0, k-1);
				if(sol2 == 1){
					if(p2>sol) cout << sol << " " << p2 << endl;
					else cout << p2 << " " << sol << endl;
				}
				else cout << sol << endl;
			}
		}
	}

	return 0;
}

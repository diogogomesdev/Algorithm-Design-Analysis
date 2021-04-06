#include <iostream>

using namespace std;

int main(){

	int M, n;
	int sol=0;

	cin >> M >> n;

	int left=0, right=M, max=0;

	int segml[n], segmr[n];

	int temporary_left, temporary_max;

	for(int i=0;i<n;i++){
		cin >> segml[i] >> segmr[i];
	}

	while(left<right){
		for(int i=0;i<n;i++){
			if(segml[i]<=left){
				if(segmr[i]<=M) temporary_max=segmr[i]-left;
				else temporary_max=M-left;

				if(temporary_max>max){
					max = temporary_max;
					temporary_left = segmr[i];
				}
			}
		}
		max=0;
		left=temporary_left;
		sol++;
	}

	cout << sol << endl;

	return 0;
}

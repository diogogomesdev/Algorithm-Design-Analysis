#include <iostream>

using namespace std;

int sumNdigits(int n){
	int sum=0;
	while(n>0){
		sum += n%10;
		n=n/10;
	}

	return sum;	
}

int main(){
	int t, n, k, sum;

	cin >> t;

	for(int i=0;i<t;i++){
		cin >> n >> k;

		sum = sumNdigits(n);

		if(sum==k){
			n++;
		}
		
		while(sumNdigits(n)!=k){
			n++;
		}



		cout << n << endl;

	}

	return 0;
}

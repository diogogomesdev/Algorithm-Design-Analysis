#include <iostream>

using namespace std;

int main(){

	int n, s, sum=0;

	cin >> n;

	for(int i=0;i<n;i++){
		cin >> s;
		if(s==42) sum++;
	}

	cout << sum << endl;

	return 0;
}

#include <iostream>
#include <string>

using namespace std;

class letter{
	public:
		char let;
		int sum=0;
		int appea=-1;
};

void insertionSort(letter *two, int size){
	if(size==1) return;
	for(int i=1;i<size;i++){
		int hold_appea = two[i].appea;
		int hold_sum = two[i].sum;
		int hold_let = two[i].let;
		int j=i;
		while(j>0 && hold_sum>=two[j-1].sum){
			if(hold_sum==two[j-1].sum){
				if(hold_appea < two[j-1].appea){
					two[j].sum = two[j-1].sum;
					two[j].appea = two[j-1].appea;
					two[j].let = two[j-1].let;			
				}
				else{
					
					two[j].sum=hold_sum;
					two[j].appea=hold_appea;
					two[j].let=hold_let;
					break;
				}
			}
			else{
				two[j].sum = two[j-1].sum;
				two[j].appea = two[j-1].appea;
				two[j].let = two[j-1].let;
			}
			j--;
		}

		two[j].sum=hold_sum;
		two[j].appea=hold_appea;
		two[j].let=hold_let;
	}
}

int main(){

	string s;
	letter one[26];

	int ch_comp, num=0;

	for(int i=0;i<26;i++){
		one[i].let = (char)(i+65);
	}

	cin >> s;

	int size= s.length();

	for(int i=0;i<size;i++){
		ch_comp = (int)s[i]-65;
		if(one[ch_comp].appea==-1){
			one[ch_comp].appea = i;
			one[ch_comp].sum++;
			num++;
		}
		else one[ch_comp].sum++;
	}

	letter two[num];
	int j=0;

	for(int i=0;i<26;i++){
		if(one[i].appea != -1){
			two[j].appea = one[i].appea;
			two[j].sum = one[i].sum;
			two[j].let = one[i].let;
			j++;
		}
	}

	insertionSort(two, num);

	for(int i=0;i<num;i++){
		cout << two[i].let << " " << two[i].sum << endl;
	}
	
	return 0;
}

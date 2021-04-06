#include <iostream>

using namespace std;

int main(){

	int n, num1=0, num2=0, result;

	cin >> n;

	char m1[6], m2[6], traco;

	int constante;
	constante = 23 * 23 * 10000;

	int special1, special2, special3, special4;

	for(int i=0;i<n;i++){
		cin >> m1[0];
		cin >> m1[1];
		cin >> traco;
		cin >> m1[2];
		cin >> m1[3];
		cin >> traco;
		cin >> m1[4];
		cin >> m1[5];
		
		cin >> m2[0];
		cin >> m2[1];
		cin >> traco;
		cin >> m2[2];
		cin >> m2[3];
		cin >> traco;
		cin >> m2[4];
		cin >> m2[5];

		//Matricula 1

		// XX-NN-NN 1ª geração
		if((m1[0]>=65 && m1[0]<=90) && 
			(m1[2]>=48 && m1[2]<=57) && 
			(m1[4]>=48 && m1[4]<=57))
		{
			
			if(m1[1]>=75 && m1[1]<87) special1 = (int)m1[1]-65-1;
			else if(m1[1]>=87 && m1[1]<89) special1 = (int)m1[1]-65-2;
			else if(m1[1]>=89) special1 = (int)m1[1]-65-3;
			else special1 = (int)m1[1]-65;
			

			if(m1[0]>=75 && m1[0]<87) special2 = (int)m1[0]-65-1;
			else if(m1[0]>=87 && m1[0]<89) special2 = (int)m1[0]-65-2;
			else if(m1[0]>=89) special2 = (int)m1[0]-65-3;
			else special2 = (int)m1[0]-65;
		

			num1 = ((int)m1[5]-48)+(((int)m1[4]-48)*10)+
			(((int)m1[3]-48)*100)+(((int)m1[2]-48)*1000)+
			((special1)*10000)+((special2)*230000);
		}
		// NN-NN-XX 2ª geração
		else if((m1[4]>=65 && m1[4]<=90) && 
			(m1[2]>=48 && m1[2]<=57) && 
			(m1[0]>=48 && m1[0]<=57))
		{
	
			if(m1[5]>=75 && m1[5]<87) special1 = (int)m1[5]-65-1;
			else if(m1[5]>=87 && m1[5]<89) special1 = (int)m1[5]-65-2;
			else if(m1[5]>=89) special1 = (int)m1[5]-65-3;
			else special1 = (int)m1[5]-65;

			if(m1[4]>=75 && m1[4]<87) special2 = (int)m1[4]-65-1;
			else if(m1[4]>=87 && m1[4]<89) special2 = (int)m1[4]-65-2;
			else if(m1[4]>=89) special2 = (int)m1[4]-65-3;
			else special2 = (int)m1[4]-65;

			num1 = ((int)m1[3]-48)+(((int)m1[2]-48)*10)+
			(((int)m1[1]-48)*100)+(((int)m1[0]-48)*1000)+
			((special1)*10000)+((special2)*230000);
			num1 += constante;
		} 
		// NN-XX-NN 3ª geração
		else if((m1[2]>=65 && m1[2]<=90) && 
			(m1[0]>=48 && m1[0]<=57) && 
			(m1[4]>=48 && m1[4]<=57))
		{
		
			if(m1[3]>=75 && m1[3]<87) special1 = (int)m1[3]-65-1;
			else if(m1[3]>=87 && m1[3]<89) special1 = (int)m1[3]-65-2;
			else if(m1[3]>=89) special1 = (int)m1[3]-65-3;
			else special1 = (int)m1[3]-65;

			if(m1[2]>=75 && m1[2]<87) special2 = (int)m1[2]-65-1;
			else if(m1[2]>=87 && m1[2]<89) special2 = (int)m1[2]-65-2;
			else if(m1[2]>=89) special2 = (int)m1[2]-65-3;
			else special2 = (int)m1[2]-65;

			num1 = ((int)m1[5]-48)+(((int)m1[4]-48)*10)+
			(((int)m1[1]-48)*100)+(((int)m1[0]-48)*1000)+
			((special1)*10000)+((special2)*230000);
			num1 += (constante * 2);

		}

		//XX-NN-XX 4ª geração
		else{
		
			if(m1[5]>=75 && m1[5]<87) special1 = (int)m1[5]-65-1;
			else if(m1[5]>=87 && m1[5]<89) special1 = (int)m1[5]-65-2;
			else if(m1[5]>=89) special1 = (int)m1[5]-65-3;
			else special1 = (int)m1[5]-65;

			if(m1[4]>=75 && m1[4]<87) special2 = (int)m1[4]-65-1;
			else if(m1[4]>=87 && m1[4]<89) special2 = (int)m1[4]-65-2;
			else if(m1[4]>=89) special2 = (int)m1[4]-65-3;
			else special2 = (int)m1[4]-65;

			if(m1[1]>=75 && m1[1]<87) special3 = (int)m1[1]-65-1;
			else if(m1[1]>=87 && m1[1]<89) special3 = (int)m1[1]-65-2;
			else if(m1[1]>=89) special3 = (int)m1[1]-65-3;
			else special3 = (int)m1[1]-65;

			if(m1[0]>=75 && m1[0]<87) special4 = (int)m1[0]-65-1;
			else if(m1[0]>=87 && m1[0]<89) special4 = (int)m1[0]-65-2;
			else if(m1[0]>=89) special4 = (int)m1[0]-65-3;
			else special4 = (int)m1[0]-65;

			num1 = ((int)m1[3]-48)+(((int)m1[2]-48)*10)+
			((special1)*100)+((special2)*2300)+
			((special3)*23*2300)+((special4)*23*23*2300);
			num1 += (constante * 3);
		}

		//Matricula 2
		// XX-NN-NN 1ª geração
		if((m2[0]>=65 && m2[0]<=90) && 
			(m2[2]>=48 && m2[2]<=57) && 
			(m2[4]>=48 && m2[4]<=57))
		{
	
			if(m2[1]>=75 && m2[1]<87) special1 = (int)m2[1]-65-1;
			else if(m2[1]>=87 && m2[1]<89) special1 = (int)m2[1]-65-2;
			else if(m2[1]>=89) special1 = (int)m2[1]-65-3;
			else special1 = (int)m2[1]-65;

			if(m2[0]>=75 && m2[0]<87) special2 = (int)m2[0]-65-1;
			else if(m2[0]>=87 && m2[0]<89) special2 = (int)m2[0]-65-2;
			else if(m2[0]>=89) special2 = (int)m2[0]-65-3;
			else special2 = (int)m2[0]-65;

			num2 = ((int)m2[5]-48)+(((int)m2[4]-48)*10)+
			(((int)m2[3]-48)*100)+(((int)m2[2]-48)*1000)+
			((special1)*10000)+((special2)*230000);
		}
		// NN-NN-XX 2ª geração
		else if((m2[4]>=65 && m2[4]<=90) && 
			(m2[2]>=48 && m2[2]<=57) && 
			(m2[0]>=48 && m2[0]<=57))
		{
	
			if(m2[5]>=75 && m2[5]<87) special1 = (int)m2[5]-65-1;
			else if(m2[5]>=87 && m2[5]<89) special1 = (int)m2[5]-65-2;
			else if(m2[5]>=89) special1 = (int)m2[5]-65-3;
			else special1 = (int)m2[5]-65;

			if(m2[4]>=75 && m2[4]<87) special2 = (int)m2[4]-65-1;
			else if(m2[4]>=87 && m2[4]<89) special2 = (int)m2[4]-65-2;
			else if(m2[4]>=89) special2 = (int)m2[4]-65-3;
			else special2 = (int)m2[4]-65;

			num2 = ((int)m2[3]-48)+(((int)m2[2]-48)*10)+
			(((int)m2[1]-48)*100)+(((int)m2[0]-48)*1000)+
			((special1)*10000)+((special2)*230000);
			num2 += constante;
		}
		// NN-XX-NN 3ª geração
		else if((m2[2]>=65 && m2[2]<=90) && 
			(m2[0]>=48 && m2[0]<=57) && 
			(m2[4]>=48 && m2[4]<=57))
		{

			if(m2[3]>=75 && m2[3]<87) special1 = (int)m2[3]-65-1;
			else if(m2[3]>=87 && m2[3]<89) special1 = (int)m2[3]-65-2;
			else if(m2[3]>=89) special1 = (int)m2[3]-65-3;
			else special1 = (int)m2[3]-65;

			if(m2[2]>=75 && m2[2]<87) special2 = (int)m2[2]-65-1;
			else if(m2[2]>=87 && m2[2]<89) special2 = (int)m2[2]-65-2;
			else if(m2[2]>=89) special2 = (int)m2[2]-65-3;
			else special2 = (int)m2[2]-65;

			num2 = ((int)m2[5]-48)+(((int)m2[4]-48)*10)+
			(((int)m2[1]-48)*100)+(((int)m2[0]-48)*1000)+
			((special1)*10000)+((special2)*230000);
			num2 += (constante * 2);
		}
		// XX-NN-XX 4ª geração
		else{

			if(m2[5]>=75 && m2[5]<87) special1 = (int)m2[5]-65-1;
			else if(m2[5]>=87 && m2[5]<89) special1 = (int)m2[5]-65-2;
			else if(m2[5]>=89) special1 = (int)m2[5]-65-3;
			else special1 = (int)m2[5]-65;

			if(m2[4]>=75 && m2[4]<87) special2 = (int)m2[4]-65-1;
			else if(m2[4]>=87 && m2[4]<89) special2 = (int)m2[4]-65-2;
			else if(m2[4]>=89) special2 = (int)m2[4]-65-3;
			else special2 = (int)m2[4]-65;

			if(m2[1]>=75 && m2[1]<87) special3 = (int)m2[1]-65-1;
			else if(m2[1]>=87 && m2[1]<89) special3 = (int)m2[1]-65-2;
			else if(m2[1]>=89) special3 = (int)m2[1]-65-3;
			else special3 = (int)m2[1]-65;

			if(m2[0]>=75 && m2[0]<87) special4 = (int)m2[0]-65-1;
			else if(m2[0]>=87 && m2[0]<89) special4 = (int)m2[0]-65-2;
			else if(m2[0]>=89) special4 = (int)m2[0]-65-3;
			else special4 = (int)m2[0]-65;
															
			num2 = ((int)m2[3]-48)+(((int)m2[2]-48)*10)+
			((special1)*100)+((special2)*2300)+
			((special3)*23*2300)+((special4)*23*23*2300);
			num2 += (constante * 3);
		}

		//Resultado

		if(num1>num2){
			result = num1 - num2;
		}
		else{
			result = num2 - num1;
		}

		cout << result << endl;

	}

	return 0;
}

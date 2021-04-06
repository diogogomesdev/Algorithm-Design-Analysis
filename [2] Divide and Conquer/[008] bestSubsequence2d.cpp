#include <iostream>
#include <cstring>

using namespace std;

int matrix[300][300];
int L, C;

int BlockMax(int* array, int beg, int end){

    int max_so_far=0, max_ending_here=0;

    for(int j=0;j<L;j++){
        
        max_ending_here += array[j];
        if(max_ending_here > max_so_far) max_so_far = max_ending_here;
        if(max_ending_here < 0) max_ending_here = 0;
    }
    return max_so_far;
}

int main(){
    int max = 0, testMax;
    cin >> L >> C;

    for(int i=0;i<L;i++){
        for(int j=0;j<C;j++){
            cin >> matrix[i][j];
        }
    }

    int array[300];

    for(int i=0;i<C;i++){
        memset(array, 0, sizeof(array));

        for(int j=i;j<C;j++){
            for(int k=0;k<L;k++){
                array[k] += matrix[k][j];
            }
            testMax = BlockMax(array, i,j);
            if(testMax > max) max = testMax;
        }
    }

    if(max > 0) cout << max << endl;
    else{
        int menor=-2000;
        for(int i=0;i<L;i++){
            for(int j=0;j<C;j++){
                if(matrix[i][j]>menor){
                    menor = matrix[i][j];
                }
            }
        }
        cout << menor << endl;
    }
    

    return 0;
}

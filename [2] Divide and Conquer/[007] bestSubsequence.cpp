#include <iostream>

using namespace std;

int main(){
    int max_so_far=0, max_ending_here=0;

    int n, num;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> num;
        max_ending_here += num;
        if(max_so_far < max_ending_here) max_so_far = max_ending_here;
        if(max_ending_here < 0) max_ending_here = 0;
    }

    cout << max_so_far << endl;

    return 0;
}

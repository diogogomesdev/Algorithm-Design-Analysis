#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int main(){

    map<string, int> bTree;
    map<string, int> :: iterator itr;

    int c1=0, c2=26, c3=351, c4=2951, c5=17901;
    string s1="a", s2="ab", s3="abc", s4="abcd", s5="abcde";
    char ch1, ch2, ch3, ch4, ch5;

    for(int i=1;i<=26;i++){
        ch1 = i+96;
        s1[0] = ch1;
        c1++;
        bTree.insert(pair<string, int>(s1, c1));
        for(int j=i+1;j<=26;j++){
            ch2 = j+96;
            s2 = s1;
            s2 += ch2;
            c2++;
            bTree.insert(pair<string, int>(s2, c2));
            for(int k=j+1;k<=26;k++){
                ch3 = k+96;
                s3 = s2;
                s3 += ch3;
                c3++;
                bTree.insert(pair<string, int>(s3, c3));
                for(int l=k+1;l<=26;l++){
                    ch4 = l+96;
                    s4 = s3;
                    s4 += ch4;
                    c4++;
                    bTree.insert(pair<string, int>(s4, c4));
                    for(int p=l+1;p<=26;p++){
                        ch5 = p+96;
                        s5 = s4;
                        s5 += ch5;
                        c5++;
                        bTree.insert(pair<string, int>(s5, c5));
                    }
                }
            }
        }
    }

    int n, num;
    cin >> n;
    string str;
    for(int i=0;i<n;i++){
        cin >> str;
        num = bTree.find(str)->second;
        if(num > 83681) cout << 0 << endl;
        else cout << num << endl;
    }

    return 0;
}

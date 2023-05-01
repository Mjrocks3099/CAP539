#include <iostream>
#include <string>
using namespace std;

void bruteForce(string str, string pattern){
    int n = str.length();
    int m = pattern.length();
    int flag =0, count = 0;
    int i,j;
    for (i = 0; i <= n - m; i++){
        for (j = 0; j < m; j++){
            if (str[i + j] != pattern[j])
        break;
    }
    if (j == m){
        flag = 1;
        if(i%2==0)
            cout <<"Pattern is present at index:- "<<i<<endl;
        count++;
        }
    }
    if(flag==0){
        cout<<"Pattern not found";
    }

}

int main(){
string str = "ABCBBABCBDDABCDABC";
string pattern = "ABD";// JUST ADD BC OR ABC YOU WILL GET INDEX
bruteForce(str, pattern);
return 0;
}

#include <iostream>
#include <string>
int count=0;
using namespace std;

void findPattern(string str, string pattern) {
    int n = str.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++) {
        bool found = true; // return if found
        for (int j = 0; j < m; j++) {
            if (str[i + j] != pattern[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            cout << "Pattern found at index " << i << " to " << i + m - 1 << endl; //patlen = m
             count++;

             //return; if you need only 1 index solution

        }


    }
    if(count==0){
            cout<<"pattern not found" ;
        }
        else{
            cout<<"total no of occurrence"<<count ;
        }
}

int main() {
    string str = "ABBCBCBABBDCBABCABBDAB";
    string pattern = "ABBD";
    findPattern(str, pattern);
    return 0;
}

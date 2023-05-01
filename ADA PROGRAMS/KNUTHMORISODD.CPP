#include <bits/stdc++.h>
using namespace std;

void pieTable(char pattern[], int M, int pie[]){
    int len = 0;
    pie[0] = 0;
    int i = 1;
    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            pie[i] = len;
            i++;
        }
        else{
            if (len != 0) {
                len = pie[len - 1];
            }
            else {
                pie[i] = 0;
                i++;
            }
        }
    }
    cout<<"\npattern is : ";
    for(int i =0; i<M; i++){
        cout<<pattern[i];
    }
    cout<<"\nPie Table\n--------\n";
    for(int i =0; i<M; i++){
        cout<<pattern[i]<<" ";
    }
    cout<<endl;
    for(int i =0; i<M; i++){
        cout<<pie[i]<<" ";
    }
}

void KMPSearch(char* pattern, char* txt){
    int M = strlen(pattern),  N = strlen(txt),  pie[M];
    pieTable(pattern, M, pie);

    cout<<"\nString is : ";
    for(int i =0; i<N; i++){
        cout<<txt[i];
    }

    int i = 0,j = 0,flag = 0;
    while ((N - i) >= (M - j)) {
        if (pattern[j] == txt[i]) {
        j++;
        i++;
        }
    if (j == M) {
        flag =1;
        if((i-j)%2!=0)
            printf("\nPattern found at index %d ", i - j);
        j = pie[j - 1];
        }

        else if (i < N && pattern[j] != txt[i]) {
            if (j != 0)
            j = pie[j - 1];
            else
            i = i + 1;
        }
    }
    if(flag == 0){
    cout<<"\npattern is not present";
    }
}

int main(){
    char txt[] = "ABCBBABCBDDABCDABC", pattern[] = "ABD";//JUST ADD BC, ABD YOU WILL GET ODD INDEX AND IF THERE IS NOT THEN NOT FOUND
    KMPSearch(pattern, txt);
    return 0;
}


#include<iostream>
#include<string.h>
using namespace std;
void computeLPSArray(char pat[], int M, int lps[])
{

int len = 0;

lps[0] = 0;

int i = 1;
while (i < M) {
if (pat[i] == pat[len]) {
len++;
lps[i] = len;
i++;
}
else
{

if (len != 0) {
len = lps[len - 1];


}
else
{
lps[i] = 0;
i++;
}
}
}
cout<<" Pattern is : "<<endl;
for(int i =0; i<M; i++){
cout<<pat[i] << " ";
}
cout<<"\n Pie Table is : "<<endl;
for(int i =0; i<M; i++){
cout<<lps[i] << " ";
}
}
void KMPSearch(char* pat, char* txt)
{
int M = strlen(pat);
int N = strlen(txt);
int lps[M];


computeLPSArray(pat, M, lps);

cout<<"\n String is : "<<endl;
for(int i =0; i<N; i++){
cout<<txt[i] << " ";
}

int i = 0;
int j = 0;
int flag = 0;
while ((N - i) >= (M - j)) {
if (pat[j] == txt[i]) {
j++;
i++;
}

if (j == M) {
flag =1;
printf("\nFound pattern at index %d ", i - j);


break;
}


else if (i < N && pat[j] != txt[i])
{

if (j!= 0)
j = lps[j - 1];
else
i = i + 1;
}

}
if(flag == 0){
    cout<<"\n Pattern is not found in the string";
}
}


int main()
{
char txt[] = "AAABBCBCBBBAAA";
char pat[] = "BBAC";

int M = strlen(pat); //STRLENGTH OF PATTERN
int N = strlen(txt);// STRLENGTH OF TEXT

int lps[M];

KMPSearch(pat, txt);
return 0;
}






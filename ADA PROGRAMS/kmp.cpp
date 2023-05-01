#include<iostream>
#include<string.h>
using namespace std;

// Fills lps[] for given pattern pat[0..M-1]
void computeLPSArray(char pat[], int M, int lps[])
{
// length of the previous longest prefix suffix
int len = 0;

lps[0] = 0; // lps[0] is always 0

// the loop calculates lps[i] for i = 1 to M-1
int i = 1;
while (i < M) {
if (pat[i] == pat[len]) {
len++;
lps[i] = len;
i++;
}
else // (pat[i] != pat[len])
{
// This is tricky. Consider the example.
// AAACAAAA and i = 7. The idea is similar
// to search step.
if (len != 0) {
len = lps[len - 1];

// Also, note that we do not increment
// i here
}
else // if (len == 0)
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

// Preprocess the pattern (calculate lps[] array)
computeLPSArray(pat, M, lps);

cout<<"\n String is : "<<endl;
for(int i =0; i<N; i++){
cout<<txt[i] << " ";
}

int i = 0; // index for txt[]
int j = 0; // index for pat[]
int flag = 0;
while ((N - i) >= (M - j)) {
if (pat[j] == txt[i]) {
j++;
i++;
}

if (j == M) {
    flag =1;
printf("\nFound pattern at index %d ", i - j);
//j = lps[j - 1];
break;
}

// mismatch after j matches
else if (i < N && pat[j] != txt[i]) {
// Do not match lps[0..lps[j-1]] characters,
// they will match anyway
if (j != 0)
j = lps[j - 1];
else
i = i + 1;
}

}
if(flag == 0){
    cout<<"\n Pattern is not found";
}
}

// Driver code
int main()
{
char txt[] = "ABABDABACDABABCABABC";
char pat[] = "ABABCD";

int M = strlen(pat);
int N = strlen(txt);

int lps[M];

KMPSearch(pat, txt);
return 0;
}

#include <bits/stdc++.h>
using namespace std;
void computeLPSArray(char *pat, int M, int *lps);

void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int flag=0;

    int lps[M];

    computeLPSArray(pat, M, lps);
    cout << "\nString is : " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << txt[i] << " ";
    }
    cout<<endl;
    int i = 0;
    int j = 0;
    while ((N - i) >= (M - j))
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            printf("\nFound pattern at index %d ", i - j);
            j = lps[j - 1];
            flag=1;

        }


        else if (i < N && pat[j] != txt[i])
        {

            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }

    }
    if(flag==0){
        cout<<"\nPATTERN NOT FOUND"<<endl;
    }

}
void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;

    lps[0] = 0;

    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {

            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    cout << "\nPattern is : " << endl;
    for (int i = 0; i < M; i++)
    {
        cout << pat[i] << " ";
    }
    cout << "\nPie Table is : " << endl;
    for (int i = 0; i < M; i++)
    {
        cout << lps[i] << " ";
    }

}

int main()
{
    char txt[] = "ABBCBCBABBDCBABC";
    char pat[] = "ABBD";
    KMPSearch(pat, txt);
    return 0;
}

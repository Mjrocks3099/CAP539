#include <iostream>
#include <string>

using namespace std;

int main()
{
    string text, pattern;
    int i, j, n, m, flag = 0;

    cout << "Enter text: ";
    //getline(cin, text);
    cin >> text;

    cout << "Enter pattern: ";
   // getline(cin, pattern);
   cin >> pattern;

    n = text.length();
    m = pattern.length();

    for (i = 0; i <= n - m; i++) {
        j = 0;
        while (j < m && text[i+j] == pattern[j]) {
            j++;
        }
        if (j == m) {
                flag =1;
            cout << "Pattern found from index position" << i <<" to index position "<<i+m-1<< endl;
            //return 0;
        }
    }
    if(flag ==0)
        {
            cout << "Pattern not found";
           // break;
        }

    return 0;
}

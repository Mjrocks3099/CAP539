#include <iostream>
#include <string>

using namespace std;

void searchPattern(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++) {

        int j;
        for (j = 0; j < m; j++) {
            if (text[i+j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            cout << '"' << pattern << "\" is present in given string from position " << i << " to position " << i+m-1 << endl;
            return;
        }
    }
    cout << '"' << pattern << "\" is not present in given string." << endl;
}

int main() {
    string text = "ABBCBCBABBDCBABCABBDAB";
    string pattern = "ABBD";
    searchPattern(text, pattern);
    return 0;
}

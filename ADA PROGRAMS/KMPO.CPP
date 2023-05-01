#include <iostream>
#include <vector>
using namespace std;

vector<int> compute_prefix(string pattern) {
    int n = pattern.size();
    vector<int> prefix(n, 0);
    int j = 0;
    for (int i = 1; i < n; i++) {
        while (j > 0 && pattern[j] != pattern[i]) {
            j = prefix[j-1];
        }
        if (pattern[j] == pattern[i]) {
            j++;
        }
        prefix[i] = j;
    }
    return prefix;
}

void search_pattern(string text, string pattern) {
    vector<int> prefix = compute_prefix(pattern);
    int n = text.size();
    int m = pattern.size();
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && pattern[j] != text[i]) {
            j = prefix[j-1];
        }
        if (pattern[j] == text[i]) {
            j++;
        }
        if (j == m) {
            if ((i - m + 1) % 2 == 1) {
                cout << "Found pattern at index " << i - m + 1 << endl;
            }
            j = prefix[j-1];
        }
    }
}

int main() {
    string text = "ABCBBABCBDDABCDABC";
    string pattern = "ABC";
    search_pattern(text, pattern);

    //pattern = "BC";
    //search_pattern(text, pattern);

    //pattern = "ABD";
    //search_pattern(text, pattern);

    return 0;
}


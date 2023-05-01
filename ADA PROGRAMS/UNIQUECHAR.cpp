#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

int main() {
    string str = "ABBAC";
    unordered_set<char> uniqueChars;

    for (char c : str) {
        uniqueChars.insert(c);
    }

    cout << "unique characters in " << str << " are: ";
    for (char c : uniqueChars) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}

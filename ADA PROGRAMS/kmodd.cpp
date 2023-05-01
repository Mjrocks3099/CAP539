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





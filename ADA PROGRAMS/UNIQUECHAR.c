#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::string str = "ABBAC";
    std::unordered_map<char, int> count;


    for (char c : str) {
        count[c]++;
    }


    std::cout << "Unique characters: ";
    for (char c : str) {
        if (count[c] == 1) {
            std::cout << c << " ";
        }
    }

    return 0;
}

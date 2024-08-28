#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>        
using namespace std;

                                                                           // Function to preprocess the bad character rule
void preprocessBadCharacter(const string& pattern, unordered_map<char, int>& badCharTable) {
    int m = pattern.length();
    for (int i = 0; i < m; i++) {
        badCharTable[pattern[i]] = i;
    }
}

                                                                            // Boyer-Moore search algorithm
int boyerMooreSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

                                                                            // Create the bad character table
    unordered_map<char, int> badCharTable;
    preprocessBadCharacter(pattern, badCharTable);

    int s = 0;                                                              // Shift of the pattern with respect to text
    while (s <= n - m) {
        int j = m - 1;

                                                                            // Compare pattern from end to start
        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }

                                                                            // If the pattern is found
        if (j < 0) {
            return s;                                                       // Pattern found at index s
        } else {
                                                                            // Calculate the shift using the bad character rule
            char badChar = text[s + j];
            int shift = max(1, j - badCharTable.get(badChar, -1));
            s += shift;
        }
    }

    return -1;                                                              // Pattern not found
}

int main() {
    string text, pattern;

                                                                            // User input for the text
    cout << "Enter the text: ";
    getline(cin, text);

                                                                            // User input for the pattern
    cout << "Enter the pattern: ";
    getline(cin, pattern);

                                                                            // Find and return the index of the pattern in the text using Boyer-Moore algorithm
    int index = boyerMooreSearch(text, pattern);

                                                                            // Display the result
    if (index != -1) {
        cout << "Pattern found at index: " << index << endl;
    } else {
        cout << "Pattern not found" << endl;
    }

    return 0;
}

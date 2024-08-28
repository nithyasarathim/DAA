#include <iostream>
#include <vector>
#include <string>

using namespace std;

                                                                            // Function to create the Longest Prefix Suffix (LPS) array
void computeLPSArray(const string& pattern, vector<int>& lps) {
    int length = 0;                                                         // Length of the previous longest prefix suffix
    int i = 1;
    lps[0] = 0;                                                             // LPS[0] is always 0

                                                                            // Loop to fill LPS array for the pattern
    while (i < pattern.length()) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

                                                                            // KMP algorithm to find the index of the first occurrence of a substring
int KMPSearch(const string& text, const string& pattern) {
    int textLen = text.length();
    int patternLen = pattern.length();

                                                                            // Create LPS array for the pattern
    vector<int> lps(patternLen);
    computeLPSArray(pattern, lps);

    int i = 0;                                                              // index for text
    int j = 0;                                                              // index for pattern

                                                                            // Loop to search for the pattern in the text
    while (i < textLen) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == patternLen) {
            return i - j;                                                   // Pattern found at index i - j
        } else if (i < textLen && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return -1;                                                              // Pattern not found
}

int main() {
    string text, pattern;

                                                                            // User input for the main text
    cout << "Enter the main text: ";
    getline(cin, text);

                                                                            // User input for the pattern (substring)
    cout << "Enter the pattern: ";
    getline(cin, pattern);

                                                                            // Find and return the index of the pattern in the text using KMP algorithm
    int index = KMPSearch(text, pattern);

                                                                            // Display the result
    if (index != -1) {
        cout << "Pattern found at index: " << index << endl;
    } else {
        cout << "Pattern not found" << endl;
    }

    return 0;
}

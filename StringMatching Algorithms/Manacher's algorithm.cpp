#include <iostream>
#include <vector>
#include <string>
using namespace std;

string preprocess(const string& s) {                                  // Function to preprocess the string by inserting '#' between characters
    string res = "#";
    for (char c : s) {
        res += c;
        res += "#";
    }
    return res;
}


string longestPalindrome(const string& s) {                            // Manacher's algorithm to find the longest palindromic substring
    string T = preprocess(s);
    int n = T.length();
    vector<int> P(n, 0);                                              // Array to store the length of palindromes centered at each character
    int C = 0, R = 0;                                                // Current center and right boundary of the palindrome

    for (int i = 0; i < n; i++) {
        int mirror = 2 * C - i;

        if (i < R) {
            P[i] = min(R - i, P[mirror]);
        }

                                                                     // Attempt to expand the palindrome centered at i
        while (i + 1 + P[i] < n && i - 1 - P[i] >= 0 && T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
            P[i]++;
        }

        if (i + P[i] > R) {                                          // If the palindrome centered at i expands past R, adjust C and R
            C = i;
            R = i + P[i];
        }
    }

    int maxLen = 0;                                                  // Find the maximum element in P     
    int centerIndex = 0;
    for (int i = 0; i < n; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    int start = (centerIndex - maxLen) / 2;                         // Extract the longest palindromic substring
    return s.substr(start, maxLen);
}

int main() {
    string s;

   
    cout << "Enter a string: ";                                     // User input for the string
    getline(cin, s);

                                                                    // Find and return the longest palindromic substring using Manacher's algorithm
    string longestPalindromicSubstring = longestPalindrome(s);

                                                                    // Display the result
    cout << "The longest palindromic substring is: " << longestPalindromicSubstring << endl;

    return 0;
}

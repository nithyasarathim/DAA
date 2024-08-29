#include<iostream>
#include<string>
using namespace std;

#define d 256                                                                   // Number of characters in the input alphabet
#define q 101                                                                   // A prime number used for hashing

                                                                                // Rabin-Karp algorithm for pattern searching
int rabinKarp(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    int i, j;
    int p = 0;                                                                  // Hash value for pattern
    int t = 0;                                                                  // Hash value for text
    int h = 1;

                                                                                // Calculate the value of h (d^(m-1) % q)
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

                                                                                // Calculate the initial hash values for pattern and first window of text
    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

                                                                                // Slide the pattern over the text
    for (i = 0; i <= n - m; i++) {
                                                                                // If hash values match, check characters one by one
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m)
                return i;                                                       // Match found
        }

                                                                                // Calculate hash value for the next window of text
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
                                                                                // Ensure positive hash value
            if (t < 0)
                t = (t + q);
        }
    }

    return -1;                                                                  // No match found
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, pattern);
    
    int index = rabinKarp(text, pattern);
    if (index != -1)
        cout << "Pattern found at index: " << index << endl;
    else
        cout << "Pattern not found" << endl;

    return 0;
}

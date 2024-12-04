#include <iostream>
#include <vector>
using namespace std;

// Function to compute the LPS array
void computeLPSArray(const string& pat, vector<int>& lps) {
    int length = 0; // Length of the previous longest prefix suffix
    int i = 1;
    lps[0] = 0;

    while (i < pat.length()) {
        if (pat[i] == pat[length]) {
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

// KMP Pattern Searching
void KMPsearch(const string& txt, const string& pat) {
    int n = txt.length();
    int m = pat.length();

    vector<int> lps(m);
    computeLPSArray(pat, lps);

    int i = 0; // index for txt
    int j = 0; // index for pat
    while (i < n) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && txt[i] != pat[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string txt = "ababcabcabababd";
    string pat = "ababd";

    KMPsearch(txt, pat);

    return 0;
}

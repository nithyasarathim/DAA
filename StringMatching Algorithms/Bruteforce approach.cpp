#include <iostream>
#include <string>
using namespace std;

                                                                            // Function to find the index of the first occurrence of a substring
int findSubstring(const string& mainStr, const string& subStr) {
    int mainLen = mainStr.length();
    int subLen = subStr.length();

                                                                            // Loop through the main string
    for (int i = 0; i <= mainLen - subLen; i++) {
        int j;

                                                                            // Loop through the substring
        for (j = 0; j < subLen; j++) {
                                                                            // If characters don't match, break the inner loop
            if (mainStr[i + j] != subStr[j]) {
                break;
            }
        }

                                                                            // If the entire substring has been matched, return the index
        if (j == subLen) {
            return i;
        }
    }

                                                                            // If the substring is not found, return -1
    return -1;
}

int main() {
    string mainStr, subStr;

                                                                            // User input for main string
    cout << "Enter the main string: ";
    getline(cin, mainStr);

                                                                            // User input for substring
    cout << "Enter the substring: ";
    getline(cin, subStr);

                                                                            // Find and return the index of the substring in the main string
    int index = findSubstring(mainStr, subStr);

                                                                            // Display the result
    if (index != -1) {
        cout << "Substring found at index: " << index << endl;
    } else {
        cout << "Substring not found" << endl;
    }

    return 0;
}

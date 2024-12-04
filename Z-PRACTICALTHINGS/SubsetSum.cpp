#include <iostream>
#include <vector>
using namespace std;

bool subsetSumBacktrack(const vector<int>& set, int sum, int index) {
    if (sum == 0) return true;
    if (index == set.size()) return false;

    if (set[index] <= sum && subsetSumBacktrack(set, sum - set[index], index + 1)) {
        return true;
    }

    return subsetSumBacktrack(set, sum, index + 1);
}

int main() {
    vector<int> set = {3, 34, 4, 12, 5, 2}; 
    int sum = 9;  
    if (subsetSumBacktrack(set, sum, 0)) {
        cout << "Subset with the given sum is found.\n";
    } else {
        cout << "Subset with the given sum is not found.\n";
    }

    return 0;
}

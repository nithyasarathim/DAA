#include <iostream>     
#include <vector> 
#include <algorithm>   
#include <climits>    
using namespace std;    
int main() {
    
    vector<vector<int>> jobs = {
        {0, 10, 15, 20},    
        {10, 0, 35, 25},   
        {15, 35, 0, 30},    
        {20, 25, 30, 0}   
    };
    vector<int> employee = {0, 1, 2, 3};

    int mintime = INT_MAX;                                                  // Initialize mintime with the maximum possible integer value (a large value).
                                                                            // Generate all possible permutations of the employee and calculate the cost for each.
    do {
        int currenttimetaken  = 0;                                          // Initialize the current time weight (total cost) to 0.
        int k = 0;                                                          // Start from employee 0 (initial city).

                                                                            // Loop through the current permutation of employee.
        for (int i = 0; i < employee.size(); i++) {
            currenttimetaken += employee[k][jobs[i]];                       // Add the time taken from the current employee (k) to the next employee in the permutation (cities[i]).
            k = employee[i];                                                // Move to the next employee(update k to be the current city).
        }
                                                                            // Update the minimum time cost if the current time is less expensive than the previously found minimum.
        mintime= min(mintime, currenttimetaken);
                                                                            // Generate the next permutation of the employee vector.
    } while (next_permutation(employee.begin(), employee.end()));
                                                                            // Print the minimum cost found.
    cout << "Minimum cost: " << mintime << endl;
    return 0;
}


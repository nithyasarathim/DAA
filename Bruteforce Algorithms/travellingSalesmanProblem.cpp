#include <iostream>     
#include <vector> 
#include <algorithm>   
#include <climits>    
using namespace std;    
int main() {
    
    vector<vector<int>> dist = {
        {0, 10, 15, 20},    
        {10, 0, 35, 25},   
        {15, 35, 0, 30},    
        {20, 25, 30, 0}   
    };
    vector<int> cities = {0, 1, 2, 3};

    int minPath = INT_MAX;                                                  // Initialize minPath with the maximum possible integer value (a large value).
                                                                            // Generate all possible permutations of the cities and calculate the cost for each.
    do {
        int currentPathWeight = 0;                                          // Initialize the current path weight (total cost) to 0.
        int k = 0;                                                          // Start from city 0 (initial city).

                                                                            // Loop through the current permutation of cities.
        for (int i = 0; i < cities.size(); i++) {
            currentPathWeight += dist[k][cities[i]];                        // Add the distance from the current city (k) to the next city in the permutation (cities[i]).
            k = cities[i];                                                  // Move to the next city (update k to be the current city).
        }

                                                                            // After visiting all cities in the permutation, add the distance to return to the starting city.
        currentPathWeight += dist[k][0];                                    // Update the minimum path cost if the current path is less expensive than the previously found minimum.
        minPath = min(minPath, currentPathWeight);
                                                                            // Generate the next permutation of the cities vector.
    } while (next_permutation(cities.begin(), cities.end()));
                                                                            // Print the minimum cost found.
    cout << "Minimum cost: " << minPath << endl;
    return 0;
}

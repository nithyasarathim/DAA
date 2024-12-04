#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
   vector<vector<int>>jobs = {
    {0, 10, 15},
    {10, 0, 20},
    {15, 20, 0}
};


    vector<int> employee = {0, 1, 2};
    int mintime = INT_MAX;

    do {
        int current=0;
        for(int i=0;i<employee.size()-1;i++){
            current+=jobs[employee[i]][employee[i+1]];
        }
        current += jobs[employee.back()][employee.front()];
        mintime =min(mintime, current);
    }while(next_permutation(employee.begin(),employee.end()));
    cout<<"Minimum cost :"<<mintime;
    return 0;
}



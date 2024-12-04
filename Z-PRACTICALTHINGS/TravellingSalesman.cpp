#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int main(){
    vector<vector<int>> dist = {
    {0, 29, 20, 21},
    {29, 0, 15, 17},
    {20, 15, 0, 28},
    {21, 17, 28, 0}
};

vector<int> city = {0, 1, 2, 3}; 
vector<int>minPathVec(city.size());
int minPath=INT_MAX;
int k=0;
do{
    int currMin=0;
    int k=0;
    for(int i=0;i<city.size();i++){
        currMin+=dist[k][city[i]];
        k=city[i];
    }
    currMin+=dist[k][0];
    if(minPath>currMin){
        minPath=currMin;
        copy(city.begin(),city.end(),minPathVec.begin());
    }
}while(next_permutation(city.begin(),city.end()));
cout<<"Min path is :"<<minPath<<endl;
for(int i:minPathVec){
    cout<<i<<" -> ";
}
}
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main(){
    int INF=INT_MAX;
    vector<vector<int>>graph{
        {0, 3, INF, 5},
        {2, 0, INF, 4},
        {INF, 1, 0, INF},
        {INF, INF, 2, 0}
    };
    for(int k=0;k<graph.size();k++){
        for(int i=0;i<graph[0].size();i++){
            for(int j=0;j<graph[0].size();j++){
                if(graph[i][k]!=INF && graph[k][j]!=INF){
                    graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
                }
            }
        }
    }
    for(int i=0;i<graph.size();i++){
        for(int j=0;j<graph[0].size();j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<"\n";
    }
}
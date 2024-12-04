#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(const pair<int,int>a, const pair<int,int> b){
    return a.second < b.second;
}
int main(){
    int start, end;
    vector<pair<int,int>> task;
    int n;
    cout<<"Enter no. of tasks :";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter start time :";
        cin>>start;
        cout<<"Enter end time :";
        cin>>end;
        task.emplace_back(start,end);
    }
    sort(task.begin(),task.end(),compare);
    int endTime= task[0].second;
    cout<<"Suggested order\nstart :"<<task[0].first<<"\tend  :"<<task[0].second<<endl;
    for(int i=1;i<=task.size();i++){
        if(task[i].first>=endTime){
            cout<<"start :"<<task[i].first<<"\tend  :"<<task[i].second<<endl;
            endTime=task[i].second;
        }
    }
}
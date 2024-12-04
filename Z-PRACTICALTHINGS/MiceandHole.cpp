#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cout<<"Enter the n value :";
    cin>>n;
    vector<int>mice;
    vector<int>hole;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        mice.push_back(val);
    }
    for(int j=0;j<n;j++){
        int val;
        cin>>val;
        hole.push_back(val);
    }
    sort(mice.begin(),mice.end());
    sort(hole.begin(),hole.end());
    int maxDiff=0;
    for(int i=0;i<n;i++){
        maxDiff=max(maxDiff,abs(hole[i]-mice[i]));
    }
    cout<<"Minimum path of maximum distance is :"<<maxDiff;
}
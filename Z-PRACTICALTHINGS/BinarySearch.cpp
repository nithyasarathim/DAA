#include <iostream>
#include <vector>
using namespace std;

int binSearch(vector<int> arr, int low, int high, int target){
    if(low>high){
        return -1;
    }
    int mid=(high+low)/2;
    if(arr[mid]<target){
        return binSearch (arr,mid+1,high,target);
    }
    else if(arr[mid]>target){
        return binSearch (arr,low,mid-1,target);
    }
    else{
        return mid;
    }
}
int main(){
    int n,num;
    cout<<"Enter the size of the array :";
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        cout<<"Enter value :";
        cin>>num;
        arr.push_back(num);
    }
    int target;
    cout<<"Enter the target value :";
    cin>>target;
    cout<<"Target value found at :"<<binSearch(arr,0,n-1,target);
}
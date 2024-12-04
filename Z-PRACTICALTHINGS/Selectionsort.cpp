#include <iostream>
#include <vector>
using namespace std;
void selectionSort(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        int minIdx=i;
        for(int j=i+1;j<arr.size();j++){
            if(arr[minIdx]>arr[j]){
                minIdx=j;
            }
        }
        int temp=arr[minIdx];
        arr[minIdx]=arr[i];
        arr[i]=temp;
    }
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int size;
    cout<<"Enter the array size :";
    cin>>size;
    vector<int> arr;
    for(int i=0;i<size;i++){
        int val;
        cin>>val;
        arr.push_back(val);
    }
    selectionSort(arr);
}
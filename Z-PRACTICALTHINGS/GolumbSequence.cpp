#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of values you want :";
    cin>>n;
    vector<int> seq(n);
    seq[1]=1;
    for(int i=2;i<n;i++){
        seq[i]=1+seq[i-seq[seq[i-1]]];
    }
    cout<<"Sequence is :";
    for(int i=1;i<n;i++){
        cout<<" "<<seq[i];
    }
}
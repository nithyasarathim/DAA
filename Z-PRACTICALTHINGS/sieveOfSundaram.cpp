#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the n value :";
    cin>>n;
    int N=(n-1)/2;
    vector<bool>isPrime(N+1,false);
    for(int i=1;i<=N;i++){
        for(int j=1;(i+j+2*i*j)<=N;j++){
            isPrime[i+j+2*i*j]=true;
        }
    }
    if(n>2){
        cout<<"2 ";
    }
    for(int i=1;i<=N;i++){
        cout<<2*i+1<<" ";
    }
}
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter no of friends :";
    cin>>n;
    vector<int> dp(n+1);
    if(n<2){
        cout<<"Friends can pair upto :"<<n;
    }
    else{
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+(i-1)*dp[i-2];
        }
        cout<<"Friends can pair upto :"<<dp[n];
    }
}
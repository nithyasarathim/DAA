#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter no. of coins :";
    cin>>n;
    vector<int> coins;
    for(int i=0;i<n;i++){
        int coin;
        cin>>coin;
        coins.push_back(coin);
    }
    int amt;
    cout<<"Enter a valid amount :";
    cin>>amt;
    vector<int> dp(amt+1);
    dp[0]=1;
    for(int coin:coins){
        for(int i=coin;i<=amt;i++){
            dp[i]+=dp[i-coin];
        }
    }
    cout<<"Maximum ways are :"<<dp[amt];
    
}
#include <iostream>
#include <climits>
#include <vector>
using namespace std;
int main(){
    vector<int> coin={1,2,5};
    int amt=3;
    vector<vector<int>>dp(coin.size()+1,vector<int>(amt+1,INT_MAX));
    for(int i=0;i<=coin.size();i++){
        dp[i][0]=0;
    }
    for(int i=1;i<=coin.size();i++){
        for(int j=1;j<=amt;j++){
            dp[i][j]=min(dp[i-1][j],dp[i][j-coin[i-1]]+1);
        }
    }
    cout<<"Minimum ways are :"<<dp[coin.size()][amt];
}
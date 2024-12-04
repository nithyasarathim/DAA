#include <iostream>
using namespace std;
int main(){
    string txt, pat;
    cin>>txt;
    cin>>pat;
    for(int i=0;i<=txt.length()-pat.length();i++){
        int count=0;
        for(int j=0;j<pat.length();j++){
            if(txt[i+j]==pat[j]){
                count++;
            }
        }
        if(count==pat.length()){
            cout<<"Index found at :"<<i;
        }
    }
}
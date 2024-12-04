#include <iostream>
#include <string>
using namespace std;

int hash1(string s){
    int hashval=0;
    for(int i=0;i<s.length();i++){
        hashval=hashval*10+(s[i]-'a');
    }
    return hashval;
}
int main(){
    string txt,pat;
    cout<<"Enter text :";
    cin>>txt;
    cout<<"Enter ptrn :";
    cin>>pat;
    int patHash=hash1(pat);
    for(int i=0;i<txt.length()-pat.length()+1;i++){
        
        if(patHash==hash1(txt.substr(i,pat.length()))){
            int count=0;
            for(int j=0;j<pat.length();j++){
                if(txt[i+j]==pat[j]){
                    count++;
                }
            }
            if(count==pat.length()){
                cout<<"Pat for at idx :"<<i;
            }
        }
    }
}
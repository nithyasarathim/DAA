#include <iostream>
#include <string>
using namespace std;

int main() {
    string k="";
    cout<<"Enter the string: ";
    cin>>k;
    int size=k.length();
    string s[size*2+2];
    int j=0;

    s[0]="#";
    for(int i=1;i<size*2;) {
        if(j<size) {
            s[i++]=k[j++];
            s[i++]="#";
        }
    }

    for(int j=0;j<size*2+1;j++) {
        cout<<s[j];
    }
    cout<<endl;

    int lps[size*2+1];
    lps[0]=0;
    
    for(int i=1;i<size*2+1;i++) {
        lps[i]=0;
        while(i-(1+lps[i])>=0 && i+(1+lps[i])<size*2+1 &&
              s[i-(1+lps[i])]==s[i+(1+lps[i])]) {
            lps[i]++;
        }
    }

    int maxVal=lps[0], maxPos=0;
    for(int i=1;i<size*2+1;i++) {
        if(lps[i]>maxVal) {
            maxVal=lps[i];
            maxPos=i;
        }
    }

    int start=maxPos-maxVal;
    int end=maxPos+maxVal;

    cout<<"Longest palindromic substring: ";
    for(int i=start;i<=end;i++) {
        if(s[i]!="#") {
            cout<<s[i];
        }
    }
    cout<<endl;

    return 0;
}

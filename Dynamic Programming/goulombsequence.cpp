#include <iostream>
using namespace std;
int main() 
{
  int N;
  cout<<"Enter the index that you need to find the value in goulomb's sequence :";
  int arr[N+1];
  arr[0]=0;
  arr[1]=1;
  for(int i=2;i<=N;i++)
    {
      arr[i]=1+(i - arr[arr[i-1]]);
    }
  cout<<arr[N];
}

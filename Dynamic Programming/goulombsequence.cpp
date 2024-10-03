#include <iostream>
using namespace std;
int main() 
{
  int N;
  cout<<"Enter the index that you need to find the value in goulomb's sequence :";
  cin>>N;
  int arr[N+1];
  arr[0]=0;
  arr[1]=1;
  for(int i=2;i<=N;i++)
    {
      arr[i]=1+arr[i - arr[arr[i-1]]];
    }
  for(int i=0;i<N;i++)
    {
      cout<<arr[i]<<" ";
}

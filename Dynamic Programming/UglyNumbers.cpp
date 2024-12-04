#include <iostream>
using namespace std;
boolean uglyNum(int n)
{
  if(n<=0)
    return false;
  while(n%2==0)
    n/=2;
  while(n%3==0)
    n/=3;
  while(n%5==0)
    n/=5;

  return n==1;
}
int main()
{
 int num;
  cout<<"Enter the n'th value for finding the required Ugly Number :";
  cin>>num;
  for(int i=0;i<num;i++)
    {
      cout<<uglyNum(n)<<" ";
    }
}

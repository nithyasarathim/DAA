#include <iostream>
using namespace std;

void swap (int *p1, int *p2)                       // get the address as pointer variable
{
    int temp = *p1;
    *p1 = *p2;                                     //swap using temp array
    *p2 = temp;
}

void selection_sort (int arr[], int n)              // get array as parameter
{
    int i,j,min_idx;                                //initialise the variables
    for (i=0;i<n-1;i++)                             // loop to iterate all over the array
    {
        min_idx =i;                                 // stores the index of 'i' as the minimum element index
        for (j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_idx])                  // compares the element one be one which is located further to the min index
            {
                min_idx =j;                          // stores the index of the minimum value of the element
            }
        }
        if(min_idx!=i)                               //checks whether the min index value is i if not, swap i with min_idx value
        {
            swap(&arr[i],&arr[min_idx]);             //pass the reference to the swap function
        }
    }
}

int main() {
    int n;
    cout<<"Enter the size of the array :";
    cin>>n;
    int arr[n];                                      //declaration, initialisation
    for (int i=0;i<n;i++){
        cout<<"Enter the value "<<i+1<< " :";
        cin>>arr[i];
    }
    selection_sort(arr,n);                          //function call
    cout<<" The result of the sorted array :\n";
    for (int i=0;i<n;i++){
        cout<<" "<<arr[i];                          //print
    }
}

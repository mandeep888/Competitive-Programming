#include <iostream>
using namespace std;

int main(){
    int n,temp;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //bubble sort
    for(int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                //swap
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }


    cout<<"Sorted array is as follows:  ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
        return 0;
}

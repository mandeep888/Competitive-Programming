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
    //selection sort

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;

            }
        }
    }
    cout<<"Sorted array is as follows:  ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
        return 0;
}

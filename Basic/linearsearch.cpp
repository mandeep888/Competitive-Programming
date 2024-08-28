#include <iostream>
using namespace std;
bool linearsearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            cout<<"the element was found at the index: "<<i<<endl;
             return true;
        }
    }
     return false;
}
int main(){
    int n,key;
    cout<<"Enter the size of array"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the element to search"<<endl;
    cin>>key;
    //linearsearch(arr,n,key);
    bool ans=linearsearch(arr,n,key);
    if(ans==false){
            cout<<"The element is not present in the array"<<endl;
    }
}


#include <iostream>
using namespace std;
int getBit(int n,int pos){
    return (n&(1<<pos))!=0;
}

int setBit(int n,int pos){
    return (n|(1<<pos));
}

int clearBit(int n,int pos){
    int mask = ~(1<<pos);
    return (n&mask);
}

int updateBit(int n , int pos , int value){
    int mask=~(1<<pos);
    n=n&mask;
    return n | (value<<pos);
}

int isPowerOfTwo(int n){
    return (n && !(n & n-1)); //to check if the number is of power two
}

int numberOfOnes(int n){
    int var = 0 ;
    while(n!=0){
        n=n&n-1;
        var++;
    }
    return var;
}

void subSets(int arr[],int n){         // IMPORTANT
    for(int i = 0 ; i<(1<<n) ; i++){
        for(int j = 0 ; j<n ; j++){
            if (i & (1<<j)){
                cout<<arr[j]<<" ";
            }
        }
        cout<<endl;
    }
}

int Unique(int arr[] , int n){
    int xorsum=0;
    for(int i = 0 ; i<n ; i++){
        xorsum=xorsum^arr[i];
    }
    return xorsum;
}
int main(){
    // GET BIT AT THE GIVEN POSITION
/*  int n,pos;
    cout<<" Enter a number :"<<endl;
    cin>>n;
    cout<<" Enter the position at which you want to get the bit:"<<endl;
    cin>>pos;
    cout<<getBit(n,pos);

    */

    // SET BIT AT GIVEN POSTION (SET MEANS SET 1 AT THAT POSITION , UNSET MEANS SET 0 AT THAT POSITION)
/*  int n,pos;
    cout<<" Enter a number :"<<endl;
    cin>>n;
    cout<<" Enter the position at which you want to get the bit:"<<endl;
    cin>>pos;
    cout<<setBit(n,pos);
    */

    // CLEAR BIT (MEANS CLEAR 1 AT THAT POSITION)
/*  int n,pos;
    cout<<" Enter a number :"<<endl;
    cin>>n;
    cout<<" Enter the position at which you want to get the bit:"<<endl;
    cin>>pos;
    cout<<clearBit(n,pos);
    */

    // UPDATE A BIT
    //cout<<updateBit(5,1,1);

//------------------------------------------------------- QUESTIONS ----------------------------------------------------------//

   // 1.) IS POWER OF TWO I.E 1-2-4-8-16-32...... SO IF DO ' NUMBER & NUMBER - 1' IT WILL GIVE ZERO IF ITS IS A POWER OF TWO
   // code:-out<<isPowerOfTwo(128);

   // 2.) WAP TO COUNT THE NUMBER OF ONES IN BINARY REPRESENTATION OF A NUMBER
   // LOGIC DO NUMBER & NUMBER -1 UNTIL THE NUMBER BECOMES ZERO AND COUNT IT
   // CODE:- cout<<numberOfOnes(19);

   // 3.) WAP TO TO PRINT ALL POSSIBLE SUBSET OF A SET
    int arr[4]={1,2,3,4};
    subSets(arr,4);

//------------------------------------------------- IMPORTANT QUESTIONS -----------------------------------------------------------//
  // 1.) FIND A UNIQUE NUMBER IN AN ARRAY EXCEPT WHICH ALL NUMBERS ARE PRESENT TWICE(IMPOERTANT POINT)..
  // NOTE : - THIS QUESTION IS AN APPLICATION OS XOR.
  // int arr[]={1,2,3,4,1,2,3};
  // cout<<Unique(arr,7)<<endl;

  // 2.) FIND TWO UNIQUE NUMBER IN AN ARRAY EXCEPT WHICH ALL NUMBERS ARE PRESENT TWICE(IMPOERTANT POINT)..
  // NOTE : - THIS QUESTION IS AN APPLICATION OS XOR.

return 0;
}

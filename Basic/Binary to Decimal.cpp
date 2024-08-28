#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int BinaryToDecimal(int n){
    int ans=0;
    int x=1;
    while(n>0){
        int temp=n%10;
        ans +=x*temp;
        x*=2;
        n/=10;
    }
    return ans;
}
int32_t main(){
    int n;
    cout<<"Enter a binary value "<<endl;
    cin>>n;

    cout<<BinaryToDecimal(n)<<endl;
}

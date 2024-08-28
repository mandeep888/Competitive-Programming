#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int OctaToDecimal(int n){
    int ans=0;
    int x=1;
    while(n>0){
        int temp=n%10;
        ans +=x*temp;
        x*=8;
        n/=10;
    }
    return ans;
}
int32_t main(){
    int n;
    cout<<"Enter a octa value "<<endl;
    cin>>n;

    cout<<OctaToDecimal(n)<<endl;
}

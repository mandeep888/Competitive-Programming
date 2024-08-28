#include <bits/stdc++.h>
using namespace std;
int reverse_binary(int n){
    int rev=0,r;
    while(n>0){
        r=n%10;
        rev=rev*10+r;
        n/=10;
    }
    return rev;
}
int add_binary(int a,int b){
    int ans =0;
    int prevcarry=0;

    while(a>0 && b>0){
        if(a%2==0 && b%2==0){
            ans=ans*10+prevcarry;
            prevcarry=0;
        }
        else if((a%2==1 && b%2==0) || (a%2==0 && b%2==1)){
            if(prevcarry==1){
                ans=ans*10 +0;
                prevcarry=1;
            }
            else{
                ans=ans*10+1;
                prevcarry=0;
            }
        }
        else{
            ans=ans*10+prevcarry;
            prevcarry=1;
        }
    a/=10;
    b/=10;
    }
    //IF ONE THE NUBERS DECREASES TO XERO THE OTHER REMAIN FOR THAT
    while(a>0){
        if (prevcarry==1){
            if(a%2==1){
                ans=ans*10+0;
                prevcarry=1;
            }
            else{
                ans=ans*10+1;
                prevcarry=0;
            }
        }
        else{
            ans=ans*10+(a%2);
        }
    a/=10;
    }
    while(b>0){
        if (prevcarry==1){
            if(b%2==1){
                ans=ans*10+0;
                prevcarry=1;
            }
            else{
                ans=ans*10+1;
                prevcarry=0;
            }
        }
        else{
            ans=ans*10+(b%2);
        }
    b/=10;
    }
    if (prevcarry==1){
        ans=ans*10+1;
    }
    //BINARY SUM IS IN REVERSE ORDER SO WE REVERSE THE NUMBER
    //ans=reverse_binary(ans);
    return ans;
}
int main(){
    int a,b;
    cout<<"Enter two binary numbers ";
    cin>>a>>b;
    cout<<add_binary(a,b);
return 0;
}

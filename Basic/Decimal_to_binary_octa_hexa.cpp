#include <bits/stdc++.h>
using namespace std;

int DecimalToBinary(int n){
    int x=1;
    int ans=0;
    while(x<=n){
        x*=2;
    }
    x/=2;  // loop will run 1 more time than we want it to so we divide it by 2 one time
    while (x>0){
        int lastDigit = n/x;
        n -= lastDigit*x;
        x/=2;
        ans = ans*10 + lastDigit;
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter a decimal number:  ";
    cin>>n;
    cout<<DecimalToBinary(n)<<endl;

}

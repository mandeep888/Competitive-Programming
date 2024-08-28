#include <bits/stdc++.h>
using namespace std;

int HexaToDecimal(string n){
    int ans=0;
    int x=1;
    int s=n.size();
    for(int i=s-1;i>=0;i--){   // from end of the string to first character
        if (n[i]>='0' && n[i]<='9'){
            ans+=x*(n[i]-'0'); // This Will be calculated using ascii codes
        }
        else if(n[i]>='A' && n[i]<='F'){
            ans+=x*(n[i]-'A'+10);  // It will convert ascii value of the characters into two digit num starting from 10 till 15.
        }
        x*=16;
    }
    return ans;
}

int32_t main(){
    string n;
    cout<<"Enter a Hexadecimal value "<<endl;
    cin>>n;

    cout<<HexaToDecimal(n)<<endl;
}

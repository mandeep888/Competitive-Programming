#include <bits/stdc++.h>
using namespace std;
void pyth_triplet(int x,int y,int z){
    if (x*x==y*y+z*z || y*y==x*x+z*z || z*z==x*x+y*y){
        cout<<"The numbers are a pythagorian triplet";
    }
    else{
        cout<<"Not a pythagorian triplet";
    }
}
int main(){
    int x,y,z;
    cout<<"Enter the pythagorian triplet"<<endl;
    cin>>x>>y>>z;
    pyth_triplet(x,y,z);
    return 0;
}

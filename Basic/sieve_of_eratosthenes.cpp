#include<iostream>
using namespace std;

void primeSieve(int n){

    int prime[n+1];
    for(int k = 0 ; k<n+1 ; k++ ){
            prime[k]=0;
    }

    for(int i = 2 ; i<=n ; i++ ){
        if(prime[i] == 0){
            for(int j = i*i ; i<=n ; j+=i){
                prime[i]=1;
            }
        }
    }
    for(int i = 2 ; i<=n ; i++ ){
        if(prime[i] == 0){
            cout<<i<<endl;
        }
    }

}
void primeFactor(int n ){
    int spf[100]={0};
    for(int k = 0 ; k<=n; k++ ){
            spf[k]=k;
    }
    for(int i = 0 ; i<=n; i++ ){
            if (spf[i]==i){
                for(int j = i*i ;j<=n ; j+=i){
                    if(spf[j] == j ){
                        spf[j]=i;
                    }
                }
            }
    }

    while (n!=1){
        cout<<spf[n]<<" ";
        n=n/spf[n];
    }
}
int main(){
    //Prime numbers using Sieve of Eratosthenes
/*    int n ;
    cout<<"Enter the number till which you want to see the prime numbers : ";
    cin>>n;
    primeSieve(n);
    */
    int n ;
    cout<<"Enter the number of which you want to see the prime factors of : ";
    cin>>n;
    primeFactor(n);
    return 0;
}

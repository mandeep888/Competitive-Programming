#include <iostream>
using namespace std;
//*********************************************************   RECURSION   *************************************************************
int sum(int n){
    if (n==0){
        return 0 ;
    }
    int prevSum = sum(n-1);
    return n + prevSum;

}

int power(int n , int p ){
    if(p==0){
        return 1 ;
    }
    int prevPower = power(n,p-1);
    return n*prevPower;
}
int factorial(int n){
    if (n==1 || n==0){
        return 1;
    }
    int prevFact = factorial(n-1);
    return n * prevFact;
}

int fibonacci(int n){
    if (n==0 || n == 1){
        return n ;
    }

    return fibonacci(n-1) + fibonacci(n-2);
    }

bool isSorted(int arr[] , int n){
    if(n==1){
        return true;
    }
    bool restArray = isSorted(arr+1 , n-1);
        return arr[0]<arr[1] && restArray;

}

void desc(int n ){
    if(n==1){
        cout<<"1"<<endl;
        return ;
    }
    cout<<n<<endl;
    desc(n-1);
}

void inc(int n){
    if(n==1){
        cout<<"1"<<endl;
        return ;
    }
    inc(n-1);
    cout<<n<<endl;
}

int firstOcc(int arr[], int n , int i , int key){
    if (i==n){
        return -1;
    }
    if(arr[i]==key){
        return i ;
    }
    return firstOcc(arr, n , i+1 , key);

}

int lastOcc(int arr[], int n , int i , int key){   //DIDN'T UNDERSTAND PROPERLY
    if (i==n){
        return -1;
    }
    int restArray = lastOcc(arr , n, i+1,key);
    if(restArray!= -1){
        return restArray;
    }
    if(arr[i]==key){
        return i ;
    }
    return -1;
}

void reverse (string s){
    if(s.length()==0){
        return;
    }
    string ros = s.substr(1);
    reverse(ros);
    cout<<s[0];
}

void replacePi(string s){
    if(s.length()==0){
        return;
    }
    if(s[0]=='p' && s[1]=='i'){
        cout<<"3.14 ";
        replacePi(s.substr(2));
    }
    else{
            cout<<s[0];
            replacePi(s.substr(1));
    }
}

void towerOfHanoi(int n , char src , char dest , char help){
    if(n==0){
        return;
    }
    towerOfHanoi(n-1,src,help,dest);
    cout<<"Move from " << src <<" to "<< dest <<endl;;
    towerOfHanoi(n-1,help,dest,src);
}

string removeDuplicates(string s ){
    if (s.length() == 0){
        return "";
    }

    char ch = s[0];
    string ans = removeDuplicates(s.substr(1));

    if (ch==ans[0]){
        return ans;
    }

    return (ch+ans);
}

string moveAllX(string s){
    if(s.length() == 0){
        return "";
    }
    char ch = s[0];
    string ans = moveAllX(s.substr(1));

    if(ch == 'x'){
        return ans+ch;
    }
    else{
        return ch+ans;
    }
}

int main(){
    // SUM TILL N
   /* int n ;
    cout<<"Enter the number till which you want sum: "<<endl;
    cin>>n;
    cout<<sum(n);
    */

    // POWER OF N RAISE TO P
    /*
    int n,p;
    cout<<"Enter the number : "<<endl;
    cin>>n;
    cout<<"Enter the power: "<<endl;
    cin>>p;
    cout<<power(n,p);
    */

    // FACTORIAL USING RECURSION
   /* int n ;
    cout<<"Enter the number: "<<endl;
    cin>>n;
    cout<<factorial(n);
    */

    //FIBONACCI
    /*int n ;
    cout<<"Enter the number: "<<endl;
    cin>>n;
    cout<<fibonacci(n);
    */

    // CHECK WHETHER THE GIVEN ELEMENT IS SOTED OR NOT
    /*int arr[]={1,2,3,4,5,6,7,8,9};
    cout<<isSorted(arr,9);
    */

    //PRINT NUMBERS TILL END IN ASC AND DESC ORDER

   /* int n ;
    cout<<"Enter a number:";
    cin>>n;
    //desc(n);
    inc(n);
    */

    // FIRST AND LAST OCCURENCCE OF A NUMBER IN AN ARRAY
   /* int arr[] = {4,2,1,2,5,2,7};
    cout<<firstOcc(arr, 7 , 0 , 2)<<endl;
    cout<<lastOcc(arr, 7 , 0 , 2)<<endl;
    */


    //####################################### RECURSION  QUESTION ON STRINGS ###############################3333

    // REVERSE A STRING USING RECURSION
    // reverse("mandeep");

    // REPLACE 'PI' IN STRING WITH 3.14
    //string s = "pipipiiiiiii";
    //replacePi(s);

    // TOWER OF HANOI
    // towerOfHanoi(3,'A', 'C', 'B');

    //REMOVE DUPLICATES 
    // cout<<removeDuplicates("aaaaaabbbbbbbbeeeeeedddddd");  //will only remove continuous duplication it cannot remove duplicates like "aba"

    // MOVE ALL X TO THE END


    return 0 ;
}

#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    // CHARACTER ARRAYS
   /* char a[6]="apple";
    int i = 0;
    while(a[i]!='\0'){
        cout<<a[i];
        i++;
    }*/
    // INPUT
    /*
    char b[11];
    cin>>b;
    cout<<b;
*/

//------------------------------------------- CHAECK PALINDROME ----------------------------------------------
    /*
    int n ;
    cout<<"Enter the size of the array : ";
    cin>>n;
    char arr[n+1];
    cin>>arr;
    bool check = 1;

    for(int i = 0 ; i< n ; i++){
        if (arr[i] != arr[n-1-i]){
            check = 0 ;
            break;
        }
    }
    if (check == 1){
        cout<<"Word is a palindrome"<<endl;
    }
    else{
        cout<<"Word is not a palindrome"<<endl;
    }
    */

// ------------------------------------ LARGEST WORD IN A SENTENCE ---------------------------------//

    /*int n ;
    cout<<"Enter the size of the array : ";
    cin>>n;
    cin.ignore();  // to clear the buffer
    char arr[n+1];
    cin.getline(arr,n);
    //cin.ignore();

    int i = 0 ;
    int currlen = 0 , maxlen = 0 , st = 0 , maxst = 0 ;
    while(1){
        if (arr[i] == ' ' || arr[i] == '\0' ){
            if (currlen>maxlen){
                maxlen = currlen;
                maxst= st;
            }
            currlen = 0 ;
            st= i+1;
        }
        else{
        currlen++;
        }
        if(arr[i] == '\0'){
            break;
        }
        i++;
    }
    cout<<maxlen<<endl;
    for (int i = 0 ; i < maxlen ; i++){
        cout<<arr[i+maxst];
    }*/

    //-------------------------------------------------------------------------------------------------------------------------
               //  STRINGS
 /*  string s = "mandeep";
    string str;
    cin>>str;
    cout<<str;
    string str1(5,'n'); // output nnnnn
    string mul;
    getline(cin,mul); // foe multiple words input
    cout<<mul;

    // FUNCTIONS OF STRING
    string s1,s2;
    s1="mansdfuhwskef";
    s2="deep";
    s1.append(s2);
    cout<<s1[1]; //accessing characters in strings
    s1.clear(); //will empty the string
    s1.compare(s2); // will compare strings based on ascii code will return a positive number if s1 is greater or vice versa 0 for same strings
    s1.empty(); //return true if s1 is empty
    s1.erase(3,4); // will erase 4 character starting from 3
    s1.find('man'); // return index of first occurence if element is present
    s1.insert(2,'lol'); // will insert lol in index 2
    s1.size(); //s1.length(); // return length
    string s = s1.substr(6,4); // will give 4 characters from 4 index
    string s1 = "54";
    int x = stoi(s1); // will convert string to inetger
    to_string(x); // will convert int to string
    // SORT
    sort(s1.begin(),s1.end()); // will sort the string
    */

//------------------------------------------------------- QUESTIONS ------------------------------
    // TO UPPERCASE

   /* string s ="sdfjhskedhajnbsdfcjsahegdfwf";
    for(int i = 0 ; i < s.size() ; i++){
        if(s[i]>='a' && s[i]<='z'){
        s[i]-=32; // s[i]+=32; to lower case
        }
    }
    cout<<s;

// USING INBLUILT FUNCTION
    transform(s.begin() //beginning iterator ,s.end() //ending iterator ,s.begin() // from where to start ,::toupper);
    */

// -------------------------------------- FORM THE BIGGEST NUMBER FROM NUMERIC STRING ----------
   /*string s="1234";
   sort(s.begin(),s.end(),greater<int>());
   cout<<s<<endl;
   */

//------------------------------ MOST FREQUENT CHARACTER -----------------------------------
    string s ="ffwrfdadfffsdfsffff";
    int freq[26];
    for(int i = 0 ; i<26 ; i++){
        freq[i]=0;
    }
    for(int i = 0 ; i<s.size();i++){
        freq[s[i]-'a']++;
    }
    char ans = 'a';
    int maxf=0;
    for(int i = 0 ; i<26; i++){
        if (freq[i]>maxf){
            maxf=freq[i];
            ans = i + 'a';
        }
    }
    cout<<maxf<<"  "<<ans<<endl;
return 0 ;
}

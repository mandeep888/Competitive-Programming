#include <bits/stdc++.h>
#include <climits>
using namespace std;

bool pairsum(int arr[],int n , int k){
    int low = 0;
    int high = n-1;
    while(low<high){
        if(arr[low]+arr[high]==k){
                cout<<low<<" "<<high<<endl;    // For sorted array
                return true;
        }
        else if(arr[low]+arr[high]>k){
                high--;
        }
        else{
            low++;
        }
    }
    return false;
    /*
    for(int i=0;i<n-1;i++){
        for(int j= i+1;j<n;j++){
            if(arr[i]+arr[j]==k){
                cout<<i<<" "<<j<<endl;
                return true;
            }
        }
    }
    return false;*/
}
int kadane(int a[],int n){
     int currentSum = 0;
     int maxSum=INT_MIN;
     for(int i= 0 ; i<n ; i++ ){
        currentSum+=a[i];
        if(currentSum<0){
            currentSum=0;
        }
        maxSum = max(maxSum,currentSum);
     }
return maxSum;
}
int main(){
    /* SUM OF ALL SUBARRAY
   int n;// no of subarray in an array is n*(n+1)/2
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<"st element:  ";
        cin>>a[i];
    }
    int curr=0;
    for(int i=0;i<n;i++){
            curr=0;
        for(int j=i;j<n;j++){
            curr+=a[j];
            cout<<curr<<endl;
        }
    } //Every subarray is a subsequence but every subsequence is not a subarray.


    /* LONGEST ARITHMETIC SUB ARRAY
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<"st element:  ";
        cin>>a[i];
    }
    int ans=2;
    int pd=a[1]-a[0];
    int j=2;
    int curr=2;
    while(j<n){
        if(pd==a[j]-a[j-1]){
            curr++;
        }
        else{
            pd=a[j]-a[j-1];
            curr=2;
        }
        ans=max(ans,curr);
        j++;
    }
    cout<<ans<<endl;*/

// RECORD BREAKER
    /* CONDITIONS FOR THE QUESTION
        :- The number of visitors on the day should be greater than each of the previous days
        :- Either it is last day or the number of days is strictly greater than number of visitors on the upcoming days
        NOTE:- First day could also be the record breaking day

        OPTIMISE APPROACH
        intuition :- if we can optimise step 1 then we can optimise our overall solution
         For step:- We need to check if a[i]>(a[0],a[1],.....,a[i-1]) which is same as
                                         a[i]>max(a[0],a[1],.....,a[i-1)
         For this we will keep a variable mx, which will store the max value till a[i] then we just need to check ,
                                          a[i]>mx,
                                          a[i]>a[i+1] (if i+1 < n)
                                          and update mx=max(mx,a[i])

                                        OVERALL TIME COMPLEXITY O(n)
    */

    /*int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n+1];
    a[n]=-1;
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<"st element:  ";
        cin>>a[i];
    }
    if (n==1){
        cout<<1<<endl;
        return 0;
    }

    int ans =0;
    int mx=INT_MIN;
    for (int i=0;i<n;i++){
        if (a[i]>mx && a[i]>a[i+1]){
                ans++;
            }
        mx=max(mx,a[i]);
    }
    cout<<ans<<endl;*/
 // ------------------------------------------------HARD ARRAY QUESTIONS -----------------------------------------------------------//
    // MINIMUM INDEX REPEATING POSITIVE VALUE
    /*int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<"st element:  ";
        cin>>a[i];
    }

    //const int N=1e6+2;
    const long int N=100000;
    int idx[N];
    for(int i=0;i<N;i++){
        idx[i]=-1;
    }

    int minidx=INT_MAX;
    for(int i=0;i<n;i++){
        if (idx[a[i]]!=-1){
            minidx=min(minidx,idx[a[i]]);
        }
        else{
            idx[a[i]]=i;
        }
    }
    if (minidx==INT_MAX){
    cout<<-1<<endl;
    }
    else{
    cout<<minidx+1<<endl;
    }*/

    // NON OPTIMISED QUESTION
    /*int n,temp=0,sum;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<"st element:  ";
        cin>>a[i];
    }
    cout<<"Enter the sum you want to search :" << endl;
    cin>>sum;
    int i;
    for( i=0;i<n;i++){
            temp=0;
        for(int j=i;j<n;j++){
            temp+=a[j];
            if(temp==sum){
                cout<<"Sum can be from index "<<i<<" to "<<j<<endl;
            }
        }
    }
    if(i==(n-1)){
        cout<<"---------NO PREFERABLE SUN=BARRAY FOUND-----------------"<<endl;
    }*/

    //--------------------------------------------------------------------------------------------------------------------------------------------------
    //     -----------------------------------------------ALL POSSIBLE SUUBARRAYS
    /*int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<"st element:  ";
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                cout<<a[k]<<" ";
            }
        cout<<endl;
        }
    }*/

//-------------------------------- MAXIMUM SUM SUB ARRAY-------------------------
   /* int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<"st element:  ";
        cin>>a[i];
    }
    int ans=0;
    int sum=0;
    for(int i=0;i<n;i++){
            sum=0;
        for(int j=i;j<n;j++){
            sum+=a[j];
            ans=max(ans,sum);
        }
    }
    cout<<ans<<endl;*/

   // ******************************************* kadane algorithm ******************************************************************
   // ******************************************* IMPORTANT ************************************************

   /* int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<"st element:  ";
        cin>>a[i];
    }
     int currentSum = 0;
     int maxSum=INT_MIN;
     for(int i= 0 ; i<n ; i++ ){
        currentSum+=a[i];
        if(currentSum<0){
            currentSum=0;
        }
        maxSum = max(maxSum,currentSum);
     }
     cout<<maxSum;
*/

//---------------------------------------------------
    /*int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<"st element:  ";
        cin>>a[i];
    }
    const long int N = 100000
    bool check[N];
    for(int i=0;i<N;i++){
        check[i]=0;
    }
    for(int i=0;i<n;i++){
        if (a[i]>= 0){
            check[a[i]] = 1;
        }
    }
    int ans = -1;
    for(int i=0;i<N;i++){
        check[i]==0;
        ans= i ;
        break;
    }
    cout<<ans;
*/
//******************************************** MAXIMUM CIRCULAR SUB ARRAY SUM ************************************************
    /*int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<"st element:  ";
        cin>>a[i];
    }
    int wrapSum,nonWrapsum,totalSum=0;
    nonWrapsum = kadane(a,n);

    for(int i=0;i<n;i++){
        totalSum+=a[i];
        a[i]=-a[i];
    }
    wrapSum = totalSum + kadane(a,n);
    cout<<max(nonWrapsum,wrapSum)<<endl;
*/

//-------------------------------------PAIR SUM -------------------------
 int arr[]={2,4,7,11,14,16,20,21};
 int key = 31;
 cout<<pairsum(arr,9,key);
return 0;
}

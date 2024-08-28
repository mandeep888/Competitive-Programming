#include <bits/stdc++.h>
#include <climits>
#include <iostream>
using namespace std;

int main(){
  /*  int n,m;
    cout<<"Enter the size of array :"<<endl;
    cin>>n>>m;
    int a[n][m];

    cout<<"Enter the elements :"<<endl;
    for(int i = 0; i<n ; i++){
        for (int j = 0 ; j< m ;j++){
            cin>>a[i][j];
        }
    }
*/
    //spiral order print
   /* int row_start= 0 , row_end=n-1 , column_start=0 , column_end=m-1;
    while (row_start<=row_end && column_start<=column_end){
        // for row start
        for(int col=column_start;col<=column_end;col++){
            cout<<a[row_start][col]<<" ";
        }
        row_start++;

        // for column end
        for(int row=row_start; row<=row_end; row++){
            cout<<a[row][column_end]<<" ";
        }
        column_end--;
        }
        // for row end
        for(int col=column_end ;col>=column_start;col--){
            cout<<a[row_end][col]<<" ";
        }
        row_end--;

        //for first column
        for(int row=column_end ; row >=row_start ; row--){
            cout<<a[row][column_start]<<" ";
        }
        column_start++;
        */

        //  TRANSPOSE OF A MATRIX
        /*int a[3][3]={{1,2,3},
                    {4,5,6},
                    {7,8,9}};
        int transpose[3][3];
        for(int i = 0 ; i< 3 ; i++){
            for (int j = 0 ; j<3;j++){
                if(i!=j){
                //swap
                //int temp = a[i][j];
                //a[i][j]= a[j][i];
                //a[j][i] = temp;
                a[i][j]=a[i][j]+a[j][i];
                a[j][i]=a[i][j]-a[j][i];
                a[i][j]=a[i][j]-a[j][i];
            }
            cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
         for(int i = 0 ; i< 3; i++){
            for (int j = 0 ; j<3;j++){
               cout<<transpose[i][j]<<" ";
            }
            cout<<endl;
        }
        */

        //-------------------------- OR --------------------------------
        /*for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
         transpose[j][i] = a[i][j];
        }

        //print
         for(int i = 0 ; i< 3; i++){
            for (int j = 0 ; j<3;j++){
               cout<<transpose[i][j]<<" ";
            }
            cout<<endl;
        }*/

        //------------------------- multipliaction of matrix -------------------------
       /*  int row1,col1,row2,col2;
         cout<<"Enter rows and columns of first matrice:"<<endl;
         cin>>row1>>col1;
         cout<<"Enter rows and columns of second matrice:"<<endl;
         cin>>row2>>col2;
         if (col1 != row2){
            cout<<"-------------------------------ERROR: MATRIX CANNOT BE MULTIPLIED -------------------------------- "<<endl;
         }
         else{
            int arr1[row1][col1];
            int arr2[row2][col2];
            int ans[row1][col2];
            // MAKINGG ANS ARRAY 0----
            for(int i = 0; i<row1 ; i++){
                for (int j = 0 ; j< col2 ;j++){
                    ans[i][j]=0;
                }
                }
            cout<<"Enter the elements of first matrice :"<<endl;
            for(int i = 0; i<row1 ; i++){
                for (int j = 0 ; j< col1 ;j++){
                    cin>>arr1[i][j];
                }
                }
            cout<<"Enter the elements of second matrice :"<<endl;
            for(int i = 0; i<row2 ; i++){
                for (int j = 0 ; j< col2 ;j++){
                    cin>>arr2[i][j];
                }
                }
            // MULTIPLICATION
            for(int i = 0; i<row1 ; i++){
                for (int j = 0 ; j< col2 ;j++){
                        for(int k=0 ; k<row2; k++){
                         ans[i][j]+= arr1[i][k]* arr2[k][j];
                        }
                }
                }
            //PRINT
            for(int i = 0 ; i< row1; i++){
            for (int j = 0 ; j<col2;j++){
               cout<<ans[i][j]<<" ";
            }
            cout<<endl;
         }
         }
         */

        //---------------------------------- Matrix search ----------------------------------//
        //  FOR ONLY THOSE MATRICES WHOSE ROWS AND COLUMNS ARE SORTED
         int n,m,key;
         cout<<"Enter the size of array :"<<endl;
         cin>>n>>m;
         int a[n][m];
         cout<<"Enter the elements :"<<endl;
         for(int i = 0; i<n ; i++){
                for (int j = 0 ; j< m ;j++){
                    cin>>a[i][j];
         }
         }
         cout<<"Enter the element you want to search: "<<endl;
         cin>>key;
         // REFER TO VIDEO IF YOU FORGOT THTE ALGO
         // WE WILL START FROM TOP RIGHT POSITION OF THE MATRICE
         int r=0, c = m -1 ;
         bool flag=false;
         while(r<n and c>=0){ // WE ARE GPING LEFT FOR SMALLER ELEMENT AND DOWN FOR LARGER ELEMENT
            if( a[r][c] == key){
                flag = true;

            }
            else if (a[r][c] > key){
                c--;
            }
            else{
                r++;
            }
         }
         if (flag == true){
            cout<<" Element found "<<endl;
         }
         else{
            cout<<" Element does not found "<<endl;
         }
return 0;
}


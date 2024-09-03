// task :- Find the closest larger or equal number to a number "n" who doesnt have consecutive 1's in binary .
// Asked by commvault
#include <bits/stdc++.h>
using namespace std;

// Function to convert integer to binary
string toBinary(int n)
{
    // int temp = n;
    string binary = "";
    while (n > 0)
    {
        binary = to_string(n % 2) + binary;
        n /= 2;
    }
    // cout<<"binary of "<<temp<<" is "<<binary<<endl;
    return binary;
}
int nitreon(int num)
{
    bool flag = true;
    while (true)
    {
        string binary = toBinary(num);
        for (int i = 0; i < binary.length(); ++i)
        {
            if (binary[i] == '1' && binary[i + 1] == '1')
            {
                flag = false;
                break;
            }
        }
        if (flag){
            return num;
        }
        else{
            num++;
            flag = true;
        }
    }
}

int main()
{
    int n;
    int num;
    cout<<"enter number of testcases"<<endl;cin>>n;
    while(n--){
        cout<<"enter number : ";cin>>num;
        cout<<nitreon(num)<<endl;
    }
    return 0;
}
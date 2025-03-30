/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
int main()
{
    int n,check;
    cin>>n;
    check=n;
    for(int i=1;i<=2*n-1;i++)
    {
        cout<<n<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n-1;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<check<<" ";
            check=check-1;


        }
        for(int z=1;z<=((2*n-1)- (2*i))-1;z++)
        {
            cout<<n-i<<" ";
        }

        for(int x=1;x<=i;x++)
        {
            cout<<check<<" ";
            check=check+1;
        }
        cout<<n;
        cout<<endl;
        check=n;
    }
    check=n;
    for(int i=0;i<n-2;i++)
    {
        for(int j=1;j<=((2*n-1)-3-2*i)/2;j++)
        {
            cout<<check<<" ";
            check=check-1;
        }
        int temp;
        temp=check;
        for(int z=1;z<=3+2*i;z++)
        {
            cout<<temp<<" ";
        }
        temp=temp+1;
        for(int j=1;j<=((2*n-1)-3-2*i)/2;j++)
        {
            cout<<temp<<" ";
            temp=temp+1;
        }
        cout<<endl;
        check=n;
    }
        for(int i=1;i<=2*n-1;i++)
    {
        cout<<n<<" ";
    }
    return 0;
}
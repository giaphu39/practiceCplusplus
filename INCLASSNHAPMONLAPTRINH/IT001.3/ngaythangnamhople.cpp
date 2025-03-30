// Write your code here
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

// lúc đầu bị sai ngay ngày 0 hoặc ngày âm, sai ngay tháng 2 
int main(){
    int ng,t,n;
    cin>>ng>>t>>n;
    if (n<=0){
        cout<<"Nam khong hop le.";
    }
    else{
        switch (t)
        {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if(ng<=31 and ng>0){
                cout<<ng<<"/"<<t<<"/"<<n<<" la ngay hop le.";
                break;
            }
            else{
                cout<<ng<<"/"<<t<<"/"<<n<<" la ngay khong hop le.";
                break;
            }
            break;
        case 4: case 6: case 9: case 11:
            if(ng<=30 and ng>0){
                cout<<ng<<"/"<<t<<"/"<<n<<" la ngay hop le.";
                break;
            }
            else{
                cout<<ng<<"/"<<t<<"/"<<n<<" la ngay khong hop le.";
                break;
            }
        case 2:
        if(n%4==0 and n%100!=0){
            if(ng<=29 and ng>0){
                cout<<ng<<"/"<<t<<"/"<<n<<" la ngay hop le.";
                break;
            }
            else{
                cout<<ng<<"/"<<t<<"/"<<n<<" la ngay khong hop le.";
                break;                
            }
        }
        else if(ng<=28 and ng>0){
            cout<<ng<<"/"<<t<<"/"<<n<<" la ngay hop le.";
            break;
        }
        else{
            cout<<ng<<"/"<<t<<"/"<<n<<" la ngay khong hop le.";
            break;
        }
            
        default:
            cout<<"Thang khong hop le.";
            break;
        }
    }
    return 0;
}
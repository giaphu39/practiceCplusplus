/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
char In[5]="0000";
void Swap(char a[], int SoConLai){
    if (SoConLai == 0) {cout<<In<<endl;return;}
    for (int i = 0; i < 4 ; i++)
        if (a[i] <= '9'){
            // Xuât thêm một số mảng ở đầu
            In[4-SoConLai] = a[i];
            //cout<<a[i];
            a[i] = a[i] + 10;
            Swap(a, SoConLai - 1);
            a[i] = a[i] - 10;
    }
}

int main()
{
    char a[] = "7654";
    Swap(a,4);// 4 = strlen(a);

    return 0;
}
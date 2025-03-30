// // Online C++ compiler to run C++ program online
// #include <iostream>
// using namespace std;
// typedef struct _Date{
//     int DD,MM,YY;
// }Date;
// typedef struct _Student{
//     int ID;
//     string Name;
//     Date BirDay;
//     float Score;
//     void output(int n){
//     for (int i = 0 ; i < n ;i++)
//         cout<<ID<<" "<<Name<<" "<<Score<<" "<<BirDay.DD<<" "<<BirDay.MM<<" "<<BirDay.YY<<endl;
//         }
// }Student;

// // void output(int n, Student sv){
// //     for (int i = 0 ; i < n ;i++)
// //         cout<<sv[i].ID<<" "<<sv[i].Name<<" "<<sv[i].Score<<" "<<sv[i].BirDay.DD<<" "<<sv[i].BirDay.MM<<" "<<sv[i].BirDay.YY<<endl;
// // }
// int main() {
//     struct _Student sv[100];
//     int n;
    
//     cin>>n;
//     for (int i = 0 ; i < n ;i++){
//         float t;
//         cin>>sv[i].ID;
        
//         cin.ignore();
//         getline(cin,sv[i].Name);//cin>>Name[i];
        
//         cin>>t;
//         sv[i].Score = t;
        
//         cin>>sv[i].BirDay.DD;
//         cin>>sv[i].BirDay.MM;
//     }
//     sv->output(n);
//     return 0;
// }
// Online C++ compiler to run C++ program online
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
typedef struct _Day{
    int DD,MM,YY;
}Day;
typedef struct _Student{
    int ID;
    string Name;
    Day BirDay;
    float Score;
}Student;

void Input(Day& d){
    cin>>d.DD>>d.MM>>d.YY;
}
void Input(Student sv[], int& n){
    cin>>n;
    for (int i = 0 ; i < n ;i++){
        float t;
        cin>>sv[i].ID;
        
        cin.ignore();
        getline(cin,sv[i].Name);//cin>>Name[i];
        
        cin>>t;
        sv[i].Score = t;
        Input(sv[i].BirDay); // nhớ phải có sv[i] để truy cập từng phần tử 
        // cin>>sv[i].BirDay.DD;
        // cin>>sv[i].BirDay.MM;
        // cin>>sv[i].BirDay.YY;
    }
}
void Print(Day d){
    cout<<d.DD<<"/"<<d.MM<<"/"<<d.YY<<"\t";
}
void Print(Student students[], int n){
    for (int i = 0 ; i < n ;i++){
        cout<<students[i].ID<<"\t"<<students[i].Name<<"\t";
        Print(students[i].BirDay);//<<sv[i].BirDay.DD<<sv[i].BirDay.MM
        cout<<students[i].Score<<endl;
    }
}

int main() {
    struct _Student sv[100];
    int n;
    Input(sv,n);
    Print(sv,n);
    return 0;
}
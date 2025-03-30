#include<iostream>
// #include<algorithm>
#include<cmath>
using namespace std;
#include<vector>


struct Point{
    float x,y;
};


void NhapMang(vector<Point>& a, int n){

    for(int i=0;i<n;i++){
        cin>>a[i].x>> a[i].y ;
    }
}

float distance(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int findClosestPoint(vector<Point> a, Point p) {
    if (a.empty()) return -1; // Trả về -1 nếu mảng rỗng

    int minIndex = 0;
    float minDistance = distance(a[0], p);

    for (int i = 0; i < a.size(); i++) {
        float currentDistance = distance(a[i], p);
        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            minIndex = i;
        }
    }
    return minIndex;
}

int main(){
    int n;cin>>n;
    vector<Point> a(n);

    NhapMang(a,n);

    Point p;
    cin>>p.x>> p.y ;

    int ans =findClosestPoint (a, p);
    if(ans== -1){
        cout<<" Mảng rỗng";
    }
    else 
        cout<<ans;
    return 0;
}
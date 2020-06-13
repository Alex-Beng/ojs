#include <set>
#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    double x1,x2,x3,x4;
    double y1,y2,y3,y4;
    while (cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4)  {
        if (x1 > x2) {
            swap(x1, x2);
        }
        if (x3 > x4) {
            swap(x3, x4);
        }

        if (y1 > y2) {
            swap(y1, y2);
        }
        if (y3 > y4) {
            swap(y3, y4);
        }
        double minx = max(x1, x3);
        double maxx = min(x2, x4);
        double miny = max(y1, y3);
        double maxy = min(y2, y4);
        if (minx > maxx || miny > maxy) {
            cout<<fixed<<setprecision(2)<<0.<<endl;
        }
        else {
            cout<<fixed<<setprecision(2)<<(maxx-minx)*(maxy-miny)<<endl;
        }
    }
    return 0;
}


// int main(int argc, char const *argv[]) {
//     double x1,x2,x3,x4;
//     double y1,y2,y3,y4;
//     while (cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4)  {
//         set<double> hori;
//         set<double> veti;
//         hori.insert(x1);   
//         hori.insert(x2);   
//         hori.insert(x3);   
//         hori.insert(x4);
//         veti.insert(y1);   
//         veti.insert(y2);   
//         veti.insert(y3);   
//         veti.insert(y4); 

//         double max_x = max(x3, x4);
//         double min_x = min(x3, x4);
//         if ((x1<min_x && x2<min_x) || (x1>max_x && x2>max_x)) {
//             cout<<fixed<<setprecision(2)<<0.<<endl;
//             continue;
//         }
//         auto it = hori.cbegin();
//         it++;
//         double l1 = *(it);
//         it++;
//         l1 = *(it)-l1;

//         it = veti.cbegin();
//         it++;
//         double l2 = *(it);
//         it++;
//         l2 = *(it)-l2;

//         cout<<fixed<<setprecision(2)<<l1*l2<<endl;
//     }
//     return 0;
// }
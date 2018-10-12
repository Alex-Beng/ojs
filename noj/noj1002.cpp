#include <map>
#include <iostream>
using namespace std;
class a {
public:
    int x;
    int y;
public:
    bool operator<(const a& t_a) const {
        return (3*y-3+x)>(3*t_a.y-3+t_a.x) ;
    }
};
map<a,int> aa;
int main(int argc, char const *argv[])
{
    a t_a;
    for (int i=0;i<3;i++) {
        t_a.x = i;
        t_a.y = t_a.x;
        aa[t_a] = i;
    }
    for (int i=0;i<3;i++) {
        t_a.x = i;
        t_a.y = t_a.x;
        cout<<aa[t_a]<<endl;
    }
    cout<<'s'<<aa.size()<<endl;
    for (map<a,int>::iterator iter = aa.begin(); iter != aa.end(); iter++ ) {
        cout<<iter->first.x<<' '<<iter->second<<endl;
    }
    return 0;
}

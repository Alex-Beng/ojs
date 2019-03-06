#include <iostream>
using namespace std;
class site{
public:
    int x;
    int y;
};

int main(int argc, char const *argv[])
{
    site points[3];
    site vec[3];
    for (int i=0; i<3; i++) {
        cin>>points[i].x>>points[i].y;
        if (i != 0) {
            vec[i].x = points[i].x-points[i-1].x;
            vec[i].y = points[i].y-points[i-1].y;
        }
    }
    vec[0].x = vec[0].x - vec[2].x;
    vec[0].y = vec[0].y - vec[2].y;
    for (int i=1; i<=3; i++) {
        if ( vec[i%3].x*vec[(i-1)%3].x + vec[i%3].y*vec[(i-1)%3].y == 0 ) {
            cout<<1<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}

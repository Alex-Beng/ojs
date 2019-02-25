#include <iostream>
#include <queue>
using namespace std;
int map[12][12] = {-1};    // -1 for building, 0 for road, positive num for steps.
bool walked[12][12] = {false};
struct site {
    int x;
    int y;
};
int main(int argc, char const *argv[])
{
    site begin_point;
    site end_point;
    cin>>begin_point.x>>begin_point.y>>end_point.x>>end_point.y;
    std::queue<site> qrq;
    qrq.push(begin_point);
    
    while (!qrq.empty()) {

    }
    return 0;
}

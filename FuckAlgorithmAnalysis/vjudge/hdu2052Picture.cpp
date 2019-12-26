#include <iostream>
using namespace std;

inline void draw_hori(int width) {
    cout<<'+';
    for (int i=0; i<width; i++) {
        cout<<'-';
    }
    cout<<'+'<<endl;
}

inline void draw_veti(int width, int height) {
    cout<<'|';
    for (int i=0; i<width; i++) {
        cout<<' ';
    }
    cout<<'|'<<endl;
}

int main(int argc, char const *argv[]) {
    int width, height;
    while(cin>>width>>height) {
        draw_hori(width);
        for (int i = 0; i < height; i++) {
            draw_veti(width, height);
        }
        draw_hori(width);
        cout<<endl;
    }
    return 0;
}
#include <iostream>
using namespace std;

int n;
int distribution[51];

int main(int argc, char const *argv[]) {
    cin>>n;
    for (int i=0; i<n; i++) {
        int age;
        cin>>age;
        distribution[age]++;
    }

    for (int i=0; i<=50; i++) {
        if (distribution[i]) {
            printf("%d:%d\n", i, distribution[i]);
        }

    }

    return 0;
}
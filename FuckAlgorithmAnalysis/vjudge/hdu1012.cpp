#include <cstdio>

#include <iostream>
using namespace std;
const int FRAC[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};	

int main(int argc, char const *argv[]) {
    printf("n e\n- -----------\n");

    int n=10;
    double t_sum = 0;
    for (int i=0; i<n; i++) {
        t_sum += 1.0/FRAC[i];
        if (i==0 || i==1 || i==2)
            cout<<i<<' '<<t_sum<<endl;
        else 
            printf("%d %.9f\n", i, t_sum);
    }
    return 0;
}
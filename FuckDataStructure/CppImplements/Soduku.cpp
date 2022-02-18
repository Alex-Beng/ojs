#include "DancingLinks.h"

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <time.h>
#include <iostream>
using namespace std;

const int N = 9;


void place(int& row, int& c1, int& c2, int& c3, int&c4, int i, int j, int k) {
    row = (i*N+j)*N + k;
    c1 = i*N + j + 1;
    c2 = N*N*1 + i*N + k;
    c3 = N*N*2 + j*N + k;
    c4 = N*N*3 + ((i/3)*3+(j/3))*N + k;
}

void output(DancingLinks& dlx) {
    int final_ans[81];
    for (int i=0; i<81; i++) {
        final_ans[(dlx.ans[i]-1)/9] = (dlx.ans[i]-1)%9 + 1;
    }
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            printf("%d", final_ans[i*9+j]);
        }
        // printf("\n");
    }
    printf("\n\n");
}

int main(int argc, char const *argv[]) {

    auto dlx = DancingLinks();

    freopen( "Expert200.txt", "r", stdin );
    double START,END;
    char g[88];
    while( ~scanf( "%s", g ) ){
        dlx.init(N*N*N, N*N*4);
        int r, c1, c2, c3, c4;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                
                for (int k=1; k<=N; k++) {
                    if (g[i*N+j]=='.' || g[i*N+j]=='0'+k) {
                        place(r, c1, c2, c3, c4, i, j, k);
                        dlx.add_node(r, c1);
                        dlx.add_node(r, c2);
                        dlx.add_node(r, c3);
                        dlx.add_node(r, c4);
                    }
                }
            }
        }
        if (dlx.dancing(0)) {
            puts(g);
            output(dlx);
        }
    }
	END = clock();
	printf( "time = %.5f ms.\n", END - START );
	return 0;
}

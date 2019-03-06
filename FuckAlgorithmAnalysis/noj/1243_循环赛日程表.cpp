#include <iostream>
using namespace std;


int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    int people_num = 1<<n;
    int dialect[people_num][people_num];
    int t_size = 1;

    dialect[0][0] = 1;
    while (t_size <= people_num/2) {
        // 初始化上面 people_num/2 行
        for (int i=0; i<t_size; i++) {
            for (int j=0; j<t_size; j++) {
                dialect[i][j+t_size] = dialect[i][j]+t_size;
            }
        }

        for (int i=0; i<t_size; i++) {
            for (int j=0; j<t_size; j++) {
                dialect[i+t_size][j] = dialect[i][j+t_size]; // 填左下的格子
                dialect[i+t_size][j+t_size] = dialect[i][j]; // 填右下的格子
            }
        }
        t_size *= 2;
    }
    for (int i=0; i<people_num; i++) {
        for (int j=0; j<people_num; j++) {
            cout<<dialect[i][j];
            if (j != people_num-1) {
                cout<<' ';
            }
        }
        cout<<endl;
    }


    return 0;
}

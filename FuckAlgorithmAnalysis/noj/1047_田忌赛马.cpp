#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    while (cin>>n && n) {
        int tianji_horse[n];
        int king_horse[n];
        for (int i=0; i<n; i++) {
            cin>>tianji_horse[i];
        }
        for (int i=0; i<n; i++) {
            cin>>king_horse[i];
        }


        int race_count = 0;
        int tianji_win_count = 0;
        int t_worst = 0;
        int k_worst = 0;
        int t_best = n-1;
        int k_best = n-1;

        std::sort(tianji_horse, tianji_horse+n);
        std::sort(king_horse, king_horse+n);

        while (race_count++ < n) {
            if (tianji_horse[t_worst] > king_horse[k_worst]) {
                tianji_win_count++;
                t_worst++;
                k_worst++;
            }
            else if (tianji_horse[t_worst] < king_horse[k_worst]) {
                tianji_win_count--;
                t_worst++;
                k_best--;
            }
            else { // if == 
                if (tianji_horse[t_best] > king_horse[k_best]) {
                    tianji_win_count++;
                    t_best--;
                    k_best--;
                }
                else {
                    if (tianji_horse[t_worst] == king_horse[k_best]) {
                        t_worst++;
                        k_best--;
                    }
                    else {
                        tianji_win_count--;
                        t_worst++;
                        k_best--;
                    }
                }
            }
        }
        cout<<tianji_win_count<<endl;
    }
    return 0;
}

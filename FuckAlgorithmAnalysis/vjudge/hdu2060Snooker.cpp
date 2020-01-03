#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int scores[7];
    scores[1] = 7;
    scores[2] = 6;
    scores[3] = 5;
    scores[4] = 4;
    scores[5] = 3;
    scores[6] = 2;

    int n;
    int ball_left, p_score, o_score;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>ball_left>>p_score>>o_score;
        int delta_score = 0;
        if (ball_left > 6) {
            delta_score = ball_left-6;
            delta_score *= 8;
            delta_score += 27;
        }
        else {
            for (int j=ball_left; j>=1; j--) {
                delta_score += scores[j];
            }
        }
        

        if (p_score+delta_score >= o_score) {
            cout<<"Yes"<<endl;
        }
        else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
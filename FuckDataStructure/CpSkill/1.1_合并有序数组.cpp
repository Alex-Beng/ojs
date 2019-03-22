#include <iostream>
using namespace std;


int main(int argc, char const *argv[]) {
    int nums[233], t_num, position_to_insert;
    int len_1, len_2;
    cin>>len_1;
    
    for (int i=0; i<len_1; i++) {
        cin>>nums[i];
    }

    cin>>len_2;
    for (int i=0; i<len_2; i++) {
        cin>>t_num;
        // do insertion
        position_to_insert = 0;
        while(true) {
            if (position_to_insert == 0 && nums[0]>= t_num) {
                break;
            }
            if (position_to_insert == len_1) {
                break;
            }
            if (nums[position_to_insert] >= t_num && t_num > nums[position_to_insert-1]) {
                break;
            }
            else {
                position_to_insert++;
            }
        }
        // cout<<t_num<<' '<<position_to_insert<<endl;

        len_1++;
        for (int k=len_1-1; k>=position_to_insert; k--) {
            nums[k] = nums[k-1];
        }
        nums[position_to_insert] = t_num;
    }  

    for (int i=0; i<len_1; i++) {
        cout<<nums[i];
        if (i != len_1-1){
            cout<<endl;
        }
        
    }
    return 0;
}

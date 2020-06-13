#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool my_comp(std::pair<int, int> a, std::pair<int, int> b) {
    return a.first>b.first;
}

int main(int argc, char const *argv[]) {
    map<int, int> poly_1, poly_2;

    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        int coef, idx;
        cin>>coef>>idx;
        poly_1[idx] = coef;
    }
    cin>>n;
    for (int i=0; i<n; i++) {
        int coef, idx;
        cin>>coef>>idx;
        poly_2[idx] = coef;
    }

    // do 乘法
    map<int, int> times_ans;
    for (auto i=poly_1.begin(); i!=poly_1.end(); i++) {
        for (auto j=poly_2.begin(); j!=poly_2.end(); j++) {
            int coef, idx;
            coef = i->second*j->second;
            idx = i->first+j->first;
            // cout<<idx<<' '<<coef<<endl;
            if (coef!=0) {
                // need to find idx first
                // times_ans[idx] = coef;
                
                auto temp = times_ans.find(idx);
                if (temp != times_ans.end()) {
                    times_ans[idx] += coef;
                }
                else {
                    times_ans[idx] = coef;
                }
            }
        }
    }
    for (auto i=times_ans.begin(); i!=times_ans.end(); i++) {
        if (i->second == 0) {
            times_ans.erase(i);
        }
    }
    if (times_ans.size() == 0) {
        printf("0 0\n");
    }
    else {
        std::vector<std::pair<int, int>> map_vec(times_ans.begin(), times_ans.end());
        sort(map_vec.begin(), map_vec.end(), my_comp);
        for (auto i=map_vec.begin(); i!=map_vec.end(); i++) {
            if (i!=map_vec.begin()) {
                cout<<' ';
            }
            cout<<i->second<<' '<<i->first;
        }
        cout<<endl;
    }
    
    // do 加法
    map<int, int> add_ans;
    for (auto i=poly_1.begin(); i!=poly_1.end(); i++) {
        add_ans.insert(*i);
    }
    for (auto i=poly_2.begin(); i!=poly_2.end(); i++) {
        auto temp = add_ans.find(i->first);
        if (temp == add_ans.end()) {
            add_ans.insert(*i);
        }
        else {
            add_ans[i->first] += i->second;
        }
        
    }

    for (auto i=add_ans.begin(); i!=add_ans.end(); i++) {
        if (i->second == 0) {
            add_ans.erase(i);
        }
    }
    if (add_ans.size() == 0) {
        printf("0 0\n");
    }
    else {
        std::vector<std::pair<int, int>> map_vec(add_ans.begin(), add_ans.end());
        sort(map_vec.begin(), map_vec.end(), my_comp);
        for (auto i=map_vec.begin(); i!=map_vec.end(); i++) {
            if (i!=map_vec.begin()) {
                cout<<' ';
            }
            cout<<i->second<<' '<<i->first;
        }
    }

    return 0;
}
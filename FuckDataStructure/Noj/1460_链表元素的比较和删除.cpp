#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int m, n, l;
    int m_list[100], n_list[100], l_list[100];
    int m_last = 0, n_last = 0, l_last = 0;

    cin>>m>>n>>l;
    int t;
    for (int i=0; i<m; i++) {
        if (i==0) {
            cin>>m_list[i];
        }
        else {
            cin>>t;
            if (t == m_list[m_last]) {
                continue;
            }  
            else {
                m_list[++m_last] = t;
            }
        }
    }

    for (int i=0; i<n; i++) {
        if (i==0) {
            cin>>n_list[i];
        }
        else {
            cin>>t;
            if (t == n_list[n_last]) {
                continue;
            }  
            else {
                n_list[++n_last] = t;
            }
        }
    }

    for (int i=0; i<l; i++) {
        if (i==0) {
            cin>>l_list[i];
        }
        else {
            cin>>t;
            if (t == l_list[l_last]) {
                continue;
            }  
            else {
                l_list[++l_last] = t;
            }
        }
    }

    int i = 0;
    int j = 0;
    int inter_list[100];
    int inter_last = -1;
    while (1) {
        if (n_list[i] < l_list[j]) {
            i++;
        }
        else if (n_list[i] > l_list[j]) {
            j++;
        }
        else {
            inter_list[++inter_last] = n_list[i];
            i++;
            j++;
        }
        if (i>n_last || j>l_last) {
            break;
        }
    }

    for (int i=0; i<=m_last; i++) {
        bool out_flag = true;
        for (int j=0; j<=inter_last; j++) {
            if (inter_list[j] == m_list[i]) {
                out_flag = false;
                break;
            }
        }
        if (out_flag) {
            cout<<m_list[i]<<endl;
        }
    }
    
    return 0;
}

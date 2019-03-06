#include <iostream>
using namespace std;
int n;
char words[233];

void show(int layer) {
    if (layer == n) {
        for (int i=0; i<n; i++) {
            cout<<words[i];
        }
        cout<<endl;
    }
    else {
        for (int i=layer; i<n; i++) {
            swap(words[layer], words[i]);
            show(layer+1);
            swap(words[layer], words[i]);
        }
    }
}

int main(int argc, char const *argv[]) {
    words[0] = 'a';
    for (int i=0; i<26; i++) {
        words[i] = words[0] + i;
    } 
    cin>>n;
    show(0);
    return 0;
}

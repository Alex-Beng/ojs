#include <iostream>
using namespace std;
int get_digit(int n) {
    if (n<10) {
        return n;
    }
    else 
        return get_digit(n/10) + n%10;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    while (n>=10) {
        n = get_digit(n);
    }
    cout<<n<<endl;
    return 0;
}

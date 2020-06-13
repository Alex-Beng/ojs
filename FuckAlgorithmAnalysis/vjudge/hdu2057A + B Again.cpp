#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    __int64 a, b;
    while(scanf("%I64X%I64X",&a,&b)!=EOF)
    {
        __int64 sum =a + b;
        if(sum < 0)
        {
            sum =- sum;
            printf("-");
        }
        printf("%I64X\n",sum);
    }
}

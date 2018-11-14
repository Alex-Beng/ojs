
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

int partition(int A[],int l,int r)
{
    int t = rand()%(r-l);
    int x = A[l+t];
    int i = l;
    int j = l+1;

    swap(A[l+t],A[l]);

    for(;j<=r;j++){
	if(A[j]<=x){
	    ++i;
	    swap(A[i],A[j]);
	}
    }

    swap(A[i],A[l]);
    return i;
}

int Quick_Sort(int A[],int l,int r, int target)
{
    if(target > r)
        return -1;
    if(l<r){
        int q = partition(A,l,r);
        if(q==target)
        	return A[q];
        else if(q>target)
        	return Quick_Sort(A,l,q-1,target);
        else
        	return Quick_Sort(A,q+1,r,target);
    }
    else return A[l];
}
int main()
{
    int A[] = {3,4,6,1,5,9,2,8,7};
    int n;
    for(int i=0;i<9;i++)
        cout<<A[i]<<' ';
    cout<<endl;
    cin>>n;

    cout<<"The "<<n<<"th largest number in the array is: "<<Quick_Sort(A,0,8,n-1);
    return 0;
}





// #include <stdio.h>
// char *a;
// main(int t, int _, char *a)
// {
//     return !0 < t ? t < 3 ? main(-79, -13, a + main(-87, 1 - _, main(-86, 0, a + 1) + a)) : 1, t < _ ? main(t + 1, _, a) : 3, main(-94, -27 + t, a) && t == 2 ? _ < 13 ? main(2, _ + 1, "%s %d %d\n") : 9 : 16 : t < 0 ? t < -72 ? main(_, t, "@n'+,#'/*{}w+/w#cdnr/+,{}r/*de}+,/*{*+,/w{%+,/w#q#n+,/#{l+,/n{n+,/+#n+,/#;#q#n+,/+k#;*+,/'r :'d*'3,}{w+K w'K:'+}e#';dq#'l q#'+d'K#!/+k#;q#'r}eKK#}w'r}eKK{nl]'/#;#q#n'){)#}w'){){nl]'/+#n';d}rw' i;# ){nl]!/n{n#'; r{#w'r nc{nl]'/#{l,+'K {rw' iK{;[{nl]'/w#q#n'wk nw' iwk{KK{nl]!/w{%'l##w#' i; :{nl]'/*{q#'ld;r'}{nlwb!/*de}'c ;;{nl'-{}rw]'/+,}##'*}#nc,',#nw]'/+kd'+e}+;#'rdq#w! nr'/ ') }+}{rl#'{n' ')# }'+}##(!!/") : t < -50 ? _ == *a ? putchar(31 [a]) : main(-65, _, a + 1) : main((*a == '/') + t, _, a + 1) : 0 < t ? main(2, 2, "%s") : *a == '/' || main(0, main(-61, *a, "!ek;dc i@bK'(q)-[w]*%n+r3#l,{}:\nuwloca-O;m .vpbks,fxntdCeghiry"), a + 1);
// }




// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int m, n, i, j, a[1001], b[1001];
//     int t;
//     while (scanf("%d", &n) == 1 && n)
//     {
//         for (i = 1; i <= n; i++)
//             scanf("%d", &a[i]);
//         for (i = 1; i <= n; i++)
//             scanf("%d", &b[i]);
//         for (i = 1; i < n; i++)
//         {
//             for (j = i + 1; j <= n; j++)
//             {
//                 if (a[i] < a[j])
//                 {
//                     t = a[i];
//                     a[i] = a[j];
//                     a[j] = t;
//                 }
//                 if (b[i] < b[j])
//                 {
//                     t = b[i];
//                     b[i] = b[j];
//                     b[j] = t;
//                 }
//             }
//         }
//         int k1, t1;
//         m = 0;
//         k1 = t1 = n;
//         j = 1;
//         for (i = 1; i <= k1;)
//         {
//             if (a[j] > b[i]) //tianji最大的比国王最大的大；
//             {
//                 m++, i++, j++;
//             }
//             else if (a[j] < b[i]) //tianji最大的比国王小，用最小的和国王最大的比，即输一场
//             {
//                 m--, i++, t1--;
//             }
//             else //最大的马都相等的情况

//             {
//                 if (a[t1] > b[k1]) //tianji最小的马比国王的最小的马大，赢一场
//                 {
//                     m++, k1--, t1--;
//                 }
//                 else if (a[t1] < b[k1]) //最小的比别人的小，不如将最小的和国王最大的比，输一场；

//                 {
//                     m--, i++, t1--;
//                 }
//                 else //最小的马力相同  随意比
//                 {
//                     if (a[t1] < b[i]) //最小的如果比国王最大的小
//                         m--;
//                     else
//                         i++, t1--; //否则最小的比国王最大的大，剩下随意比
//                 }
//             }
//         }
//         printf("%d\n", m);
//     }
//     return 0;
// }

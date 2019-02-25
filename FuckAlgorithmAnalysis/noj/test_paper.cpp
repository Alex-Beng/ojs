#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;

int main(int argc, char const *argv[]) {
    cout<<"卧槽"<<endl;
    getchar();
    return 0;
}




// #include <iostream>
// #include <stdio.h>
// using namespace std;
// int x, y;
// int mark[1000000];
// int sum[1000000];
// int a[1000000];
// int sta = 0, endd = 0, res = 0;
// void solve()
// {
//     int m;
//     while (1) {
//         if (a[sta] == x) {
//             res = sum[sta];
//             break;
//         }

//         m = a[sta] + 1;
//         if (mark[m] == 0) {
//             sum[++endd] = sum[sta] + 1;
//             mark[m] = 1;
//             a[endd] = m;
//         }

//         m = a[sta] - 1;
//         if (mark[m] == 0) {
//             sum[++endd] = sum[sta] + 1;
//             mark[m] = 1;
//             a[endd] = m;
//         }
//         m = a[sta];
//         if (m % 2 == 0) {
//             m = a[sta] / 2;
//             if (mark[m] == 0) {
//                 sum[++endd] = sum[sta] + 1;
//                 mark[m] = 1;
//                 a[endd] = m;
//             }
//         }
//         sta++;
//     }
// }

// int main()
// {
//     cin >> x >> y;
//     sum[0] = 0;
//     a[0] = y;
//     solve();
//     cout << res << endl;
//     return 0;
// }

// #include<iostream>
// #include<cstdio>
// #include<cstdlib>
// #include<cstring>
// #include<algorithm>
// #include<string>
// #define INF 999999999
// #define N 1001
// #define MOD 1000000007
// using namespace std;
// int a[N][N];
// int main()
// {
//     int m;
//     int k=1,half=1;
//     cin>>m;

//     int n=1<<m;
//     a[0][0]=1;
//     while(k<=m)
//     {
//         for(int i=0;i<half;i++)
//             for(int j=0;j<half;j++)
//                 a[i][j+half]=a[i][j]+half;

//         for(int i=0;i<half;i++)
//             for(int j=0;j<half;j++)
//             {
//                 a[i+half][j]=a[i][j+half];
//                 a[i+half][j+half]=a[i][j];
//             }
//         half*=2;
//         k++;
//     }
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//             printf("%d ",a[i][j]);
//         cout<<enddl;
//     }
//     return 0;
// }

// // #include <stdio.h>
// // int a[3][3];
// // int used[10];
// // void search(int n);
// // void testout();
// // void output();
// // int main()
// // {
// //     search(0);
// //     return 0;
// // }
// // void search(int n)
// // {
// //     int i, j;
// //     if (n == 9)
// //         testout();
// //     else

// //         {
// //             for (i = 1; i <= 9; i++)
// //             {
// //                 if (used[i] == 0)
// //                 {
// //                     a[n / 3][n % 3] = i;
// //                     used[i] = 1; //表示该数已经被用过，不能再一次使用
// //                     search(n + 1);
// //                     used[i] = 0;

// //                 }
// //             }
// //         }
// // }
// // void testout()
// // {
// //     int i, j, flag = 1;
// //     for (i = 0; i < 3; i++)
// //     {
// //         if (a[i][0] + a[i][1] + a[i][2] != 15 || a[0][i] + a[1][i] +
// a[2][i] != 15)
// //         {
// //             flag = 0;
// //             break;
// //         }
// //     }
// //     if (flag == 1)
// //     {
// //         if (a[0][0] + a[1][1] + a[2][2] != 15 || a[0][2] + a[1][1] +
// a[2][0] != 15)
// //              flag = 0;
// //     }
// //      if (flag == 1) output();
// // }
// // void output()
// // {
// //     int i, j;
// //     for (i = 0; i < 3; i++)
// //     {
// //         for (j = 0; j < 3; j++)
// //         {
// //             if (j <= 1)

// //                 {
// //                     printf("%d ", a[i][j]);

// //                 }
// //              if (j == 2)
// //             {
// //                   printf("%d", a[i][j]);

// //             }
// //         }
// //         printf("\n");
// //     }
// //     printf("\n");

// // }

// // // #include <iostream>
// // // #include <ctime>
// // // #include <cstdlib>
// // // using namespace std;

// // // void swap(int &a, int &b)
// // // {
// // //     int c = a;
// // //     a = b;
// // //     b = c;
// // // }

// // // int partition(int A[],int l,int r)
// // // {
// // //     int t = rand()%(r-l);
// // //     int x = A[l+t];
// // //     int i = l;
// // //     int j = l+1;

// // //     swap(A[l+t],A[l]);

// // //     for(;j<=r;j++){
// // // 	if(A[j]<=x){
// // // 	    ++i;
// // // 	    swap(A[i],A[j]);
// // // 	}
// // //     }

// // //     swap(A[i],A[l]);
// // //     return i;
// // // }

// // // int Quick_Sort(int A[],int l,int r, int target)
// // // {
// // //     if(target > r)
// // //         return -1;
// // //     if(l<r){
// // //         int q = partition(A,l,r);
// // //         if(q==target)
// // //         	return A[q];
// // //         else if(q>target)
// // //         	return Quick_Sort(A,l,q-1,target);
// // //         else
// // //         	return Quick_Sort(A,q+1,r,target);
// // //     }
// // //     else return A[l];
// // // }
// // // int main()
// // // {
// // //     int A[] = {3,4,6,1,5,9,2,8,7};
// // //     int n;
// // //     for(int i=0;i<9;i++)
// // //         cout<<A[i]<<' ';
// // //     cout<<enddl;
// // //     cin>>n;

// // //     cout<<"The "<<n<<"th largest number in the array is:
// "<<Quick_Sort(A,0,8,n-1);
// // //     return 0;
// // // }

// // // #include <stdio.h>
// // // char *a;
// // // main(int t, int _, char *a)
// // // {
// // //     return !0 < t ? t < 3 ? main(-79, -13, a + main(-87, 1 - _,
// main(-86, 0, a + 1) + a)) : 1, t < _ ? main(t + 1, _, a) : 3, main(-94, -27 +
// t, a) && t == 2 ? _ < 13 ? main(2, _ + 1, "%s %d %d\n") : 9 : 16 : t < 0 ? t
// < -72 ? main(_, t,
// "@n'+,#'/*{}w+/w#cdnr/+,{}r/*de}+,/*{*+,/w{%+,/w#q#n+,/#{l+,/n{n+,/+#n+,/#;#q#n+,/+k#;*+,/'r
// :'d*'3,}{w+K w'K:'+}e#';dq#'l
// q#'+d'K#!/+k#;q#'r}eKK#}w'r}eKK{nl]'/#;#q#n'){)#}w'){){nl]'/+#n';d}rw' i;#
// ){nl]!/n{n#'; r{#w'r nc{nl]'/#{l,+'K {rw' iK{;[{nl]'/w#q#n'wk nw'
// iwk{KK{nl]!/w{%'l##w#' i; :{nl]'/*{q#'ld;r'}{nlwb!/*de}'c
// ;;{nl'-{}rw]'/+,}##'*}#nc,',#nw]'/+kd'+e}+;#'rdq#w! nr'/ ') }+}{rl#'{n' ')#
// }'+}##(!!/") : t < -50 ? _ == *a ? putchar(31 [a]) : main(-65, _, a + 1) :
// main((*a == '/') + t, _, a + 1) : 0 < t ? main(2, 2, "%s") : *a == '/' ||
// main(0, main(-61, *a, "!ek;dc i@bK'(q)-[w]*%n+r3#l,{}:\nuwloca-O;m
// .vpbks,fxntdCeghiry"), a + 1);
// // // }

// // // #include <bits/stdc++.h>
// // // using namespace std;
// // // int main()
// // // {
// // //     int m, n, i, j, a[1001], b[1001];
// // //     int t;
// // //     while (scanf("%d", &n) == 1 && n)
// // //     {
// // //         for (i = 1; i <= n; i++)
// // //             scanf("%d", &a[i]);
// // //         for (i = 1; i <= n; i++)
// // //             scanf("%d", &b[i]);
// // //         for (i = 1; i < n; i++)
// // //         {
// // //             for (j = i + 1; j <= n; j++)
// // //             {
// // //                 if (a[i] < a[j])
// // //                 {
// // //                     t = a[i];
// // //                     a[i] = a[j];
// // //                     a[j] = t;
// // //                 }
// // //                 if (b[i] < b[j])
// // //                 {
// // //                     t = b[i];
// // //                     b[i] = b[j];
// // //                     b[j] = t;
// // //                 }
// // //             }
// // //         }
// // //         int k1, t1;
// // //         m = 0;
// // //         k1 = t1 = n;
// // //         j = 1;
// // //         for (i = 1; i <= k1;)
// // //         {
// // //             if (a[j] > b[i]) //tianji最大的比国王最大的大；
// // //             {
// // //                 m++, i++, j++;
// // //             }
// // //             else if (a[j] < b[i])
// //tianji最大的比国王小，用最小的和国王最大的比，即输一场
// // //             {
// // //                 m--, i++, t1--;
// // //             }
// // //             else //最大的马都相等的情况

// // //             {
// // //                 if (a[t1] > b[k1])
// //tianji最小的马比国王的最小的马大，赢一场
// // //                 {
// // //                     m++, k1--, t1--;
// // //                 }
// // //                 else if (a[t1] < b[k1])
// //最小的比别人的小，不如将最小的和国王最大的比，输一场；

// // //                 {
// // //                     m--, i++, t1--;
// // //                 }
// // //                 else //最小的马力相同  随意比
// // //                 {
// // //                     if (a[t1] < b[i]) //最小的如果比国王最大的小
// // //                         m--;
// // //                     else
// // //                         i++, t1--;
// //否则最小的比国王最大的大，剩下随意比
// // //                 }
// // //             }
// // //         }
// // //         printf("%d\n", m);
// // //     }
// // //     return 0;
// // // }

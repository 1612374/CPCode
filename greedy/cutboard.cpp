//https://www.hackerrank.com/challenges/board-cutting/problem
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct arr{
    long long int val;
    int horv;
};
typedef struct arr arr;
int compare(arr c , arr d){
    if(c.val > d.val){
        return 1;
    }
    return 0;
}
arr a[2000020];
int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n,m;
        scanf("%d %d",&m,&n);
        int i;
        int j=0;
        for(i=1;i<m;i++){
            scanf("%lld",&a[j].val);
            a[j].horv=1;    // its a horizontal line
            j++;
        }
        for(i=1;i<n;i++){
            scanf("%lld",&a[j].val);
            a[j].horv=0;  // verticle line
            j++;
        }
        sort(a,a+j,compare);
        int v=0;
        int h=0;
        long long int cost=0;
        for(i=0;i<j;i++){
            if(a[i].horv==1){  // making cut along horizontal line
                cost=(cost+(a[i].val*(v+1))%1000000007)%1000000007;
                h++;
            }
            else if(a[i].horv==0){  // making cut along verticle line
                cost=(cost+(a[i].val*(h+1))%1000000007)%1000000007;
                v++;
            }
        }
        printf("%lld\n",cost);
    }
    return 0;
}

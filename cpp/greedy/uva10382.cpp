#include <iostream>
#include <cstdio>
#include <string>
#include <sstream> 
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cassert>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define IN(x,y) ((y).find((x))!=(y).end())
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define DBG cerr << "debug here" << endl;
#define DBGV(vari) cerr << #vari<< " = "<< (vari) <<endl;

//typedef long long ll;
const int MAX = 1e4+12;
int di[]={-2,-2,0, 0, 2, 2};
int dj[]={-1, 1,2,-2, 1,-1};

typedef struct{
    double l,r;
}DD;

int cmp(const void *i, const void *j){
    DD *a,*b;
    a = (DD *)i, b = (DD *)j;
    return a->l < b->l ? -1 : 1;
}

int main(){
    //freopen("xx.txt","r",stdin);
    int n,l,w;
    double x,r;
    int i,j;
    while (scanf("%d %d %d", &n, &l, &w) == 3){
        int m=0;
        DD D[MAX];
        for (i = 0; i < n; i++){
            scanf("%lf %lf", &x, &r);
            if (r > w/2.0){
                double ll = x - sqrt(r*r - w*w/4.0);
                double rr = x + sqrt(r*r - w*w/4.0);
                D[m].l = ll, D[m].r = rr;
                m++;
            }
        }
        qsort(D, m, sizeof(DD), cmp);
        int ch, flag = 0;
        double right = 0;
        for (i = 0, j = 0;i < m; i++){
            double tmp =right;
            ch = -1;
            while (j < m && D[j].l <= right){
                if (D[j].r > tmp){
                    tmp = D[j].r;
                    ch = j;
                }
                j++;
            }
            if (tmp >= l){
                printf("%d\n", i+1);
                flag = 1;
                break;
            }
            if (ch == -1)
                break;
            right = tmp;
        }
        if (!flag) puts("-1");
    }

    return 0;
}

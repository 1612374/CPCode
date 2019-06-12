#include <bits/stdc++.h>
using namespace std;

struct interval{
    double left;
    double right;
};

bool comp(interval a, interval b){
    if (a.left == b. left)
        return a.right > b.right;
    return a.left < b.left;
}

int n,l,w,x,r;
double dx;
int sz;

int main(){
    //freopen("t.txt", "r", stdin);
    //freopen("tt.txt", "w", stdout);
    while(cin >> n >> l >> w){
        sz = 0; 
        interval dat[10001];
        
        for (int i = 0; i < n; i++)
        {
            cin >> x >> r;
            if (r*1.0 > w/2.0){
                dx = sqrt(r*r - w*w/4.0);
        
                dat[sz].left = (double)x - dx;
                dat[sz].right = (double)x + dx;
                sz++;
            }
        }
        sort(dat, dat + sz, comp);
        
        int i,j;
        int ch, flag = 0;
        double right = 0;
        for (i = 0, j = 0;i < sz; i++){
            double tmp =right;
            ch = -1;
            while (j < sz && dat[j].left <= right){
                if (dat[j].right > tmp){
                    tmp = dat[j].right;
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

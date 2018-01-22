//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=351
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

typedef long long ll;
const int MAX = 1e6+1;
int di[]={-2,-2,0, 0, 2, 2};
int dj[]={-1, 1,2,-2, 1,-1};

int s,c;
double x;
vector <double> M;
vector <double> C[10];

double sum(vector<double> k){
    double ans = 0;
    for (int i = 0; i < k.size(); i++){
        ans+=k[i];
    }
    return ans;
}

int main(){
    //freopen("xx.txt","r",stdin);
    int test = 0;
    while (cin >> c >> s){
        test++;
        FOR(i, 10){
            C[i].clear();
        }
        M.clear();
        double A = 0;
        FOR(i,s)
        {
            cin >> x;
            M.pb(x);
            A+=x;
        } 
        A/=c;
        //cout << A << endl;
        if (s<2*c) 
            FOR(i,2*c-s) M.pb(0);
        sort(M.rbegin(), M.rend());
        int c_sz = 1;
        bool rev = false; 
        FOR(i,SZ(M)){
            //cout << M[i] << " ";
            C[c_sz].pb(M[i]);
            if (!rev) c_sz++;
            else c_sz--;
            if (c_sz==c+1)
            {
                c_sz--;
                rev = true;
            }
        }
        //cout << endl;
        cout << "Set: #" << test << endl;
        double res = 0;
        FORI(i,c){
            cout << " ";
            cout << i-1 << ": ";
            for (int j = 0; j < C[i].size(); j++){
                if (C[i][j]) cout << C[i][j] << " ";
            }

            res += abs(A - sum(C[i]));
            cout << endl;
            
        }

        cout << "IMBALANCE = ";
        printf("%.5lf\n\n", res);
    }
       

    return 0;
}


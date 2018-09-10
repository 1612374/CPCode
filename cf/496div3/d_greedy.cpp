//http://codeforces.com/contest/1005/problem/D
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int res = 0;
int main(){

    string s;
    cin >> s;

    int n = s.length();
    int pre = 0;

    for (int i = 0; i < n; i++){
        int d =s[i] - '0';
        
        if (d % 3 == 0){
            res ++;
            pre = 0;
            //cout << d << endl;
        }
        else{
            //cout << d << " d" << endl;
            pre = pre*10 +d;
            //cout << pre << " pre" << endl;
            if (pre % 3 == 0){
                //cout << pre << " f" << endl;
                res++;
                pre = 0;
            }    
            else{
                int  tmp = 100;
                while(pre / tmp){
                    //cout << "cai loz me" << endl;
                    int k = pre % tmp;
                    if (k % 3 == 0)
                    {
                        //cout << k << " d" << endl;
                        res++;
                        pre = 0;
                        break;
                    }
                }
            }
            
        }
        
    }

    cout << res;
    return 0;
}

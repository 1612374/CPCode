//https://www.hackerrank.com/challenges/beautiful-pairs/problem
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3 + 12;
int a[MAX], b[MAX], n;
bool checkA[MAX] = {false}, checkB[MAX] = {false};
int main(){
    freopen("xx.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int res = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (a[i] == b[j] && checkB[j] == false){
                checkB[j] = true;
                checkA[i] = true;
                res++;
                break;
            }
        }
    }
    if (res == n){
        cout << res - 1;
        return 0;
    }
    for (int i = 0; i < n; i++){
        if (checkB[i] == false){
            for (int j = 0; j < n; j++){
                if (checkA[j]==false){
                    res++;
                    cout << res;
                    return 0;
                }
            }
        }
    }
    cout << res;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a[100000], dp[100000], track[100000];
int main(){
    freopen("input.txt","r",stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) dp[i] = 1;
    for (int i = 2; i <= n; i++){ 
        int maxdplocal=0, index = 0;
        for (int j = 1; j < i; j++){
            if (dp[j] > maxdplocal && a[j]<a[i]) {maxdplocal = dp[j]; index = j;}
        }
        dp[i]+=maxdplocal;
        track[i]=index;
    }
    int maxdpglobal = 0, index = 0;
    for (int i = 1; i <=n; i++)
        if (dp[i] > maxdpglobal) {
            maxdpglobal = dp[i];
            index = i;
        }
    int temp = index;
    stack <int> st;
    while (true){
        index = track[index];
        if (index == 0) break;
        st.push(a[index]);
    }
    while (!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << a[temp] << " ";
    return 0;
}

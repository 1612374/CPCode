#include <bits/stdc++.h>
using namespace std;
string s;
int dp[100][100],n;
void init(){
    for (int i=0;i<100;i++)
        dp[i][i]=1;
}
int main(){
    init();
    // dp[i][j] = dp[i+1][j] + dp[i][j-1] -dp[i+1][j-1] + T;
    //if (s[i] == s[j]) T = dp[i+1][j-1] + 1;
    //else T=0;
    cin >>s;
    n=s.length();
    for (int k=1;k<=n-1;k++)
        for (int i=0;i<=n-1-k;i++){
            int j= i+k;
            dp[i][j]=dp[i+1][j]+dp[i][j-1];
            if (s[i]==s[j])
                dp[i][j]++;
            else dp[i][j]-=dp[i+1][j-1];
        }
    cout << dp[0][n-1]<<endl;
    return 0;
}

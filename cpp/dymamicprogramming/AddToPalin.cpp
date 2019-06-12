#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int dp[100][100]={0};
    int n=s.length();
    for (int k=1;k<=n-1;k++)
        for (int i=0; i <= n-1-k;i++){
            int j = i+k;
            if (s[i]==s[j])
                dp[i][j]=dp[i+1][j-1];
            else dp[i][j]=min(dp[i+1][j], dp[i][j-1])+1;
        }
    cout << dp[0][n-1];
    return 0;
}

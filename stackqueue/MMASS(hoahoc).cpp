#include <bits/stdc++.h>
using namespace std;

bool isnum(char c){
 return (c >= '0' && c <= '9');
}

bool isele(char c){
  return c == 'C' || c == 'H' || c == 'O';
}

int val(char c){
  if (c == 'C')
    return 12;
  if (c == 'H')
    return 1;

  return 16;
}

int main(){
      string s;
      cin >> s;
      stack <int> st;
      int ans = 0;
      for (int i = 0; i < s.length(); i++){
         if (isele(s[i]))
            st.push(val(s[i]));
         else if (s[i] == '(')
            st.push(1000);
         else if (isnum(s[i])){
            int tmp = st.top();
            tmp *= (s[i] - '0');
            st.pop();
            st.push(tmp);
         }
         else if (s[i] == ')'){
            int sum = 0;
            while (st.top() != 1000){
                sum += st.top();
                st.pop();
            }
            st.pop();
            st.push(sum);

         }

      }

      while (st.empty() == false){
         ans+=st.top();
         st.pop();
      }
      cout << ans;
      return 0;
}

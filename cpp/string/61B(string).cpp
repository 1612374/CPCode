#include <bits/stdc++.h>
using namespace std;

string s1, s2, s3;

bool isupp(char c){
  return (c >= 'A' && c <= 'Z');
}

void loww(char &c){

   if (isupp(c))
	c += 32;
}


void erase_sym_format(string &s){
   for (int i = 0; i < s.length(); i++){
       if (isalpha(s[i]) == false){
          s.erase(s.begin() + i);
          i--;
       }
       else loww(s[i]);
   }

}

string app(string s1, string s2, string s3){
   string res("");
   res.insert(res.length(), s1);
   res.insert(res.length(), s2);
   res.insert(res.length(), s3);

   return res;
}

bool ok(string s){

   string tmp = app(s1, s2, s3);
   if (tmp == s) return true;
   tmp = app(s1, s3, s2);
   if (tmp == s) return true;
   tmp = app(s2, s1, s3);
   if (tmp == s) return true;
   tmp = app(s2, s3, s1);
   if (tmp == s) return true;
   tmp = app(s3, s2, s1);
   if (tmp == s) return true;
   tmp = app(s3, s1, s2);
   if (tmp == s) return true;

   return false;
}
int main(){

   cin >> s1 >> s2 >> s3;

   erase_sym_format(s1);
   erase_sym_format(s2);
   erase_sym_format(s3);

   //cout << s1 << "  " << s2 << "  " << s3 << endl;

   int n;
   cin >> n;
   string tmp;
   for (int i = 0; i < n; i++){
      cin >> tmp;
      erase_sym_format(tmp);
      //cout << tmp << endl;
      if (ok(tmp)) cout << "ACC" << endl;
      else cout << "WA" << endl;
   }

   return 0;
}
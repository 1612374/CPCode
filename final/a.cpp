//Fibsieve’s Fantabulous
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
 long long int n,t,j=0;
   cin>>t;
   while(t--)
   {   cin>>n;
       long long int sq=ceil(sqrt(n));
       long long int r=sq*sq-n;
       long long int x,y;
       if(r<sq)
       {
           y=r+1;
           x=sq;
       }
       else
       {
           x=2*sq-r-1;
           y=sq;
       }
       if( sq & 1)
	       swap(x,y);
       printf("Case %lld: %lld %lld\n",++j,x,y);

   }
   return 0;

	return 0;
}
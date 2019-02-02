#include <bits/stdc++.h>

using namespace std;
//Manacher's Algorithm

string strongestPalin(string str)
{
    int n=str.size();
    if(n==1)
        return str;
    n=2*n+1; //we have n characters and n-1 middle characters and 2 end characters in total.
    int lps[n]; //lps array to store generated lps values
    memset(lps,0,sizeof(lps));//filling the lps table with 0
    lps[1]=1;
    int center=1,right=2,cleft,d=-1,mxlps=0,mxc=0;//positions
    bool flag;
    for (int i=2;i<n;i++)
    {
        cleft =2*center-i,d=right-i;
        flag=false;
        if(d>0)
        {
            if(lps[cleft]<d)
                lps[i]=lps[cleft];
            else if(lps[cleft]==d&&i==n-1)
                lps[i]=lps[cleft];
            else if(lps[cleft]==d&&i<n-1)
            {
                    lps[i]=lps[cleft];
                    flag=true;
            }
            else if(lps[cleft]>d)//we have check every distance and decide whether to expand lps table or not.
            {
                lps[i]=d;
                flag=true;
            }
        }
        else
        {
            lps[i]=0;
            flag=true;
        }
        if (flag==1)
        {
            //only for odds we have to check whether flipping position characters are same or not.
            //we have to also check whether it is int the range or not
            while(((i+lps[i])<n&&(i-lps[i])>0)&&(((i+lps[i]+1)%2==0)||(str[(i+lps[i]+1)/2]==str[(i-lps[i]-1)/2])))
            {
                lps[i]++;
            }
        }
        if (i+lps[i]>right)
        {
            center=i;
            right=i+lps[i];
        }
        if(lps[i]>mxlps)
        {
            mxlps=lps[i];
            mxc=i;
        }
    }
    int s=(mxc- mxlps)/2,f=s+mxlps-1;
    if(f==s)
        f=0,s=0;
    string ans="";
    for(int i=s;i<=f;i++)
        ans+=str[i];
    return ans;
}


int main()
{

    string str;
    while(cin>>str)
        cout<<strongestPalin(str)<<endl;
    return 0;
}

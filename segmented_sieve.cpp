#include <iostream>
#include <math.h>
using namespace std;
#define max 1000000
#define max2 9000010
int flag[max];
long long int arr[max];
#define on(x) (flag[x/64]&(1<<((x%64)/2)))
#define mark(x) flag[x/64] |=(1<<((x%64)/2))
int main()
{
    int t;
    cin>>t;
    long long int num=sqrt(max);
    for(long long int i=3;i<num;i+=2)
    {
        if(!on(i))
        {
        for(long long int j=i*i;j<max;j+=i<<1)
        {
            mark(j);
        }
        }
    }
    long long int j=1;
    arr[0]=2;
    for(long long int i=3;i<max;i+=2)
    {
        if(!on(i))
        {
            arr[j]=i;
            j++;
        }

    }
    long long int sss=j;
    for(int i=0;i<t;i++)
    {
        long long int m,n;
        cin>>m>>n;
        if(m>n)
            swap(m,n);
        for(int j=m;j<=n;j++)
        {
            if(j==1)
                continue;
            int tmp;
            tmp=sqrt(j);
            bool st=true;
            for(int k=0;k<sss;k++)
            {
                if(arr[k]>tmp)
                    break;
                if(j%arr[k]==0)
                {
                    st=false;
                    break;
                }
            }
            if(st==true)
                cout<<j<<endl;
        }
        cout<<endl;
    }
    return 0;
}

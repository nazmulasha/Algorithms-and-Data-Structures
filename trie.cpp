#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct node{
      bool endmark;
      node *next[10];
      node()
      {
          endmark=false;
          for(int i=0;i<10;i++)
          {
              next[i]=NULL;
          }
      }
}*root;

bool insert(char *str,int len)
{
    bool ss=true;;
    node *curr=root;
    if(curr->endmark==true)
        return false;
    for(int i=0;i<len-1;i++)
    {
        int id=str[i]-'0';
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
        if(curr->endmark)
            return false;
    }
    int id=str[len-1]-'0';
    if(curr->next[id]==NULL)
        curr->next[id]=new node();
    else
        return false;
    curr=curr->next[id];
    curr->endmark=true;
    return ss;
}

bool search(char *str,int len)
{
    node *curr=root;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'a';
        if(curr->next[id]==NULL)
            return false;
        curr=curr->next[id];
    }
    return curr->endmark;
}

void del(node* curr)
{
    for(int i=0;i<10;i++)
    {
        if(curr->next[i])
        {
            del(curr->next[i]);
            delete curr->next[i];
        }
    }
}
int main()
{
    int tt;
    cin>>tt;
    for(int t=1;t<=tt;t++){
    root=new node();
    int n;
    cin>>n;
    bool ss=true;
    for(int i=0;i<n;i++)
    {
        char str[50];
        scanf("%s",str);
        if(ss==false)
            continue;
        if(insert(str,strlen(str))==false)
            ss=false;
    }
    del(root);
    printf("Case %d: ",t);
    if(ss)
        printf("YES\n");
    else
        printf("NO\n");
        }
    return 0;
}

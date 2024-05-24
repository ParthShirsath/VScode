#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct stack{
    int top,data[MAX];
}s1;
void init()
{
    s1.top=-1;
}
int isempty()
{
    if(s1.top==-1)
    return 1;
    else
    return 0;
}
void push(int num)
{
    s1.data[++s1.top]=num;
}
int pop()
{
    int num;
    num=s1.data[s1.top];
    s1.top--;
    return num;
}
void topological(int a[10][10],int n)
{
    static int indegree[10],visited[10]={0};
    int i,j,v,w;
    for(i=1;i<=n;i++)
    {
       for(j=1;j<=n;j++)
        {
            indegree[i]+=a[j][i];
        }
    }
    while(1)
    {
        for(v=1;v<=n;v++)
        {
           if(indegree[v]==0 && visited[v]==0)
           {
                push(v);
                printf("V%d--->",v);
                visited[v]=1;
           }
        }

        if(isempty())
        break;
    
        v=pop();    
        for(w=1;w<=n;w++)
        {
            if(a[v][w]==1)
            indegree[w]=indegree[w]-1;
        }
    }
}
int main()
{
    int i,j,n,a[10][10];
    printf("Enter Limit");
    scanf("%d",&n);
    printf("enter the matrix");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&a[i][j]);

    topological(a,n);
}
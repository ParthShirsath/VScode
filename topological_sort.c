#include<stdio.h>
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
    static int visited[10]={0};
    int i,j;
    int v,w;
    static int ind[10]={0};

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            ind[i]=ind[i]+a[j][i];
        }
    }

    while(1)
    {
        for(v=0;v<n;v++)
            if((visited[v]==0)&&(ind[v]==0))
            {
                push(v);
                printf("V%d---->",v+1);
                visited[v]=1;
            }
        if(isempty())
        break;

        v=pop();
        for(w=0;w<n;w++)
        {
            if(a[v][w]==1)
            ind[w]=ind[w]-1;
        }
    }
}
int main()
{
    int n,i,a[10][10],j;
    printf("Enter Number of vertices");
    scanf("%d",&n);
    printf("\nEnter matrix");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nAdjecency Matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    topological(a,n);
}
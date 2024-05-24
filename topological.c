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
    return s1.data[s1.top--];
}
void topological(int a[10][10],int n)
{
    int visited[20]={0},ind[10]={0};
    //count indegree
    int i,j,v;
    init();
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    ind[i]+=a[j][i];

    //sorting

    while(1)
    {
        for(v=1;v<=n;v++)
        {
            if(visited[v]==0 && ind[v]==0)
            {
                push(v);
                printf("V%d--->",v);
                visited[v]=1;
            }
        if(isempty())
        break;

        v=pop();
        for(int w=1;w<=n;w++)
        {
            if(a[v][w]==1)
            ind[w]-=1;
        }
        }
    }


}
int main()
{
    int n,i,a[10][10],j;
    printf("Enter Number of vertices");
    scanf("%d",&n);
    printf("\nEnter matrix");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Adjecency Matrix");

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d",a[i][j]);
        }
    }
    topological(a,n);
}
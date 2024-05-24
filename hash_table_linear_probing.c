#include<stdio.h>

int ht[10]={-1};
int hash_function(int num,int i)
{
    return (num%10+i)%10;
}
int insert(int num)
{
    int i,index;
    for(i=0;i<=10;i++)
    {
        index=hash_function(num,i);
        if(ht[index]==-1)
        {
            ht[index]=num;
        }
        break;
    }
}
void display()
{
    int i;
    for(i=0;i<=10;i++)
    {
        printf("%d\t",ht[i]);
    }
}
int main()
{
    int ch,num;
    do{
        printf("\nMENU:-\n1:Insert\n2:Delete:\n3:Search:\n4:display\n");
        printf("Enter The Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter The Number:");
                   scanf("%d",&num);
                   insert(num);
                   break;
            /*case 2:printf("\nEnter The Number To Delete:");
                   scanf("%d",&num);
                   delete(num);
                   break;
            case 3:printf("\nEnter The Number To Search:");
                   scanf("%d",&num);
                   search(num);
                   break;*/
            case 4:display();
                   break;
        }
    }while(ch<5);
}
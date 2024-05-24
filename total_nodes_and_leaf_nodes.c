#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
    int data;
    struct tree *left,*right;
}TREE;
TREE *bst(int n,TREE *root)
{
    int i,num;
    TREE *newnode,*parent,*temp;
    for(i=0;i<n;i++)
    {
        newnode=(TREE *)malloc(sizeof(TREE));
        newnode->left=newnode->right=NULL;
        printf("Enter The Number=");
        scanf("%d",&newnode->data);
        num=newnode->data;
        if(root==NULL)
        {
            root=newnode;
            continue;
        }
        temp=root;
        while(temp!=NULL)
        {
            parent=temp;
            if(temp->data>num)
            temp=temp->left;
            else
            temp=temp->right;
        }
        if(parent->data>num)
        parent->left=newnode;
        else
        parent->right=newnode;
    }
    return root;
}

void inorder_display(TREE *root)
{
    TREE *temp=root;
    if(temp!=NULL)
    {
        inorder_display(temp->left);
        printf("%d->",temp->data);
        inorder_display(temp->right);
    }
}
int count_node(TREE *root)
{
    static int c=0;
    TREE *temp=root;
    if(temp!=NULL)
    {
        c++;
        count_node(temp->left);
        count_node(temp->right);
    }
    return c;
}
int count_leaf_node(TREE *root)
{
    static int c=0;
    TREE *temp=root;
    if(temp!=NULL)
    {
        if(temp->left==NULL && temp->right==NULL)
        c++;
        count_leaf_node(temp->left);
        count_leaf_node(temp->right);
    }
    return c;
}
int main()
{
    int n,c;
    TREE *root;
    printf("Enter The Limit=");
    scanf("%d",&n);
    root=bst(n,NULL);
    inorder_display(root);
    c=count_node(root);
    printf("\nTOTAL NODE IN THE TREE=%d",c);
    printf("\nTOTAL LEAF NODE IN THE TREE=%d",count_leaf_node(root));
}
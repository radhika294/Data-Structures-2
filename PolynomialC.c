#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int pow ;
    struct node *next;
};
    struct node *create(struct node *start)
{
    struct node *newnode, *ptr;
    int info,info2;
    scanf("%d%d",&info&info2);
    while(info!=-1)
    {
        newnode=(struct node *)malloc(sizeof(struct node *));
        newnode->coeff=info;
        newnode->pow=info2
        if(start==NULL)
        {
            start=newnode;
            printf("enter -1 to end\n");
            scanf("%d%d",&info&info2);
        }
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=newnode;
            newnode->prev=ptr;
            newnode->next=NULL;
            printf("enter -1 to end\n");
            scanf("%d%d",&info&info2);
        }
    }
    return start;
}
};
int main()
{
    struct node *p1;
    struct node *p2;
    printf("Enter polynomial one\n");
    p1=create(p1);
    printf("Enter polynomial two\n");
    p2=create(p2);
    return 0;
}
void add(struct node *poly1,struct node *poly2)
{
    struct node *poly;

}


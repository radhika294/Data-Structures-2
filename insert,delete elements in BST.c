#include <stdio.h>
#include <stdlib.h>

int size=0;

struct node
{
    int key;
    struct node *left,*right;
} *root;
int isEmpty() { return size==0;}//checks if the BST is empty
void add(struct node *cur, struct node *tmp) // inserts a value into the BST
{
    if(tmp->key<cur->key)
    {
        if(cur->left==NULL)
            cur->left=tmp;
        else
            add(cur->left,tmp);
    }
    else
    {
        if(cur->right==NULL)
            cur->right=tmp;
        else
            add(cur->right,tmp);
    }
}
void insert(int val) //helper function
{
    struct node *tmp=(struct node*)malloc(sizeof(struct node));
    tmp->key=val;
    tmp->left=NULL;
    tmp->right=NULL;

    if(isEmpty())
        root=tmp;
    else
        add(root,tmp);
    size++;
}
int search(struct node *cur,int val) //searches for a value in the BST
{
    if(cur==NULL)
        return 0;
    if(cur->key==val)
        return 1;

    if(val<cur->key)
        return search(cur->left,val);
    else
        return search(cur->right,val);
}
struct node *inorderSuccessor(struct node *cur){ return minValue(cur->right);} //helper function
struct node *deleteVal(struct node *cur, int val) //removes a value from the BST
{
    if(cur==NULL) return cur;

    if(val<cur->key)
        cur->left= deleteVal(cur->left,val);
    else if(val>cur->key)
        cur->right= deleteVal(cur->right,val);
    else
    {
        struct node *tmp;

        if(cur->left==NULL)
        {
            tmp=cur->right;
            free(cur);
            return tmp;
        }
        else if(cur->right==NULL)
        {
            tmp=cur->left;
            free(cur);
            return tmp;
        }

        tmp= inorderSuccessor(cur);
        cur->key=tmp->key;

        cur->right=deleteVal(cur->right,tmp->key);
    }
    return cur;
}
//void remove(int val) { deleteVal(root,val); size--;} //helper function
void input(int a[], int N) //enter values into an array
{
    for(int i=0;i<N;i++)
    {
        printf("Enter a number\n");
        scanf("%d",&a[i]);
    }
}
void create(int a[], int N) //creates a BST from an array
{
    for(int i=0;i<N;i++)
        insert(a[i]);
}
int main() //main method
{
    int N;
    printf("Creating a BST from an array...\n");
    printf("Enter the size of the array\n");
    scanf("%d",&N);
    int a[N];
    input(a,N);

    create(a,N);

    int choice=-1,val,tmp;
    do
    {
        printf("BINARY SEARCH TREE:\n");
        printf("1) Insert a value\n");
        printf("2) Remove a value\n");
        printf("3) Search for a value\n");
        printf("4) Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                printf("Enter a value to insert\n");
                scanf("%d",&val);
                insert(val);
                printf("%d inserted into the BST\n\n",val);
                break;
            case 2:
                printf("Enter a value to delete\n");
                scanf("%d",&val);
                if(contains(val))
                {
                    remove(val);
                    printf("%d deleted from the BST\n\n", val);
                }
                else
                    printf("%d not present in the BST\n\n",val);
                break;
            case 3:
                printf("Enter a value to be searched\n");
                scanf("%d",&val);
                tmp=contains(val);
                if(tmp)
                    printf("Value found\n\n");
                else
                    printf("Value not found!\n\n");
                break;
            case 4:
                printf("Good bye.\n\n");
                break;
            default:
                printf("Invalid choice\n\n");
        }
    }
    while (choice!=4);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node{
int data ;
struct node* link ;
};

struct node* root = NULL ;

void append ()
{

    struct node* temp ;
    temp = (struct node*)malloc(sizeof(struct node*));
    temp->link = NULL ;
    printf ("\nPlz Enter the data : ");
    scanf ("%d",&temp->data);
    if (root == NULL)
        root = temp ;
    else {
        struct node* p ;
        p = root ;
        while (p->link != NULL)
            p = p->link ;
        p->link = temp ;
    }
}

void display ()
{

    struct node* p ;
    p = root ;
    while (p->link != NULL){
        printf ("%d-->",p->data);
        p = p->link ;
    }
    printf ("%d",p->data);
}

int length ()
{
    int len = 1 ;
    struct node* p ;
    p = root ;
    while (p->link != NULL){
        len++;
        p = p->link ;
    }
    return len ;
}

void deletefun ()
{
    int i ;
    printf ("\nPlz Enter the loc\n");
    int loc ;
    scanf ("%d",&loc);
    struct node* p ;
    p = root ;
    struct node* q ;
    struct node* temp;
    for ( i = 1 ; i < loc ; i++ )
        p = p->link;
    q = p->link ;
    temp = q->link ;
    p->link = temp ;
    q->link = NULL ;
    free (q);
}

void main ()

{

    for (i = 0 ; i < 5 ; i++ )
        append();
    printf ("\nDisplaying\n");
    display();
}

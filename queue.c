#include <stdio.h>
#include <stdlib.h>

int array [100];
int size = 5 ;
int front = -1 ;
int rear = -1 ;

void push (int element)
{

    if (rear == size-1){
        printf ("\nQueue Overflow\n");
        exit (-1);
    }
    else {
        if (front == -1){
            front++;
        }
        rear++;
        array[rear] = element ;
    }
}

void pop ()
{

    if (front > rear){
        printf ("\nQueue Underflow");
        exit (-1);
    }
    else {
        front++;
    }
}

void display ()
{

    int  i ;
    for ( i = rear ; i >= front ; i-- )
        printf ("%d ",array[i]);
}

void main ()

{

    push (1);
    push (2);
    push (3);
    push (4);
    push (5);
    display ();
    printf ("\nNow poping \n");
    pop();
    display ();
}

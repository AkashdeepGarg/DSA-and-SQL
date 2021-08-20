#include <stdio.h>

int array [100];
int size = 5 ;
int top = -1 ;

void push (int element)
{

    if (top == size-1){
        printf ("\nStack Overflow\n");
        exit (-1);
    }
    else{
        top++;
        array[top] = element ;
    }
}
void pop ()
{

    if (top == -1){
        printf ("\nStack Underflow\n");
        exit (-1);
    }
    else{
        top--;
    }
}

void display ()
{

    int i ;
    for ( i = top ; i >= 0 ; i-- )
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
}

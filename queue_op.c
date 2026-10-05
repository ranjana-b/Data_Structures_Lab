#include <stdio.h>
#define MAX 3
int queue[MAX];
int f=-1;
int r=-1;

void insert()
{
    int item;
     if(r==MAX-1)
     {
         printf("Queue Overflow");

     }
     else
     {
        printf(" Enter the item into the queue: ");
        scanf("%d",&item);

        if(f==-1)
         f=0;

         r++;
         queue[r]=item;
         printf("%d inserted into the queue",item);
     }
    printf("\n");
}

void delete()
{
    if(f==-1|| f>r)
    {
        printf("Queue Underflow!");
    }
    else{
        printf(" The removed element is: %d  ", queue[f]);
        f++;

         if(f>r)
         {
             f=r=-1;
         }
    }

}

void display()
{

    if(f==-1)
    {
        printf("Queue Underflow!");
    }
    else
    {
        printf("The Queue elements are: ");

        for(int i=f;i<r+1;i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main(){
int choice;

while(1)
{
    printf("\n ----OPERATIONS ON QUEUE----- ");
    printf("\n1.INSERT   ");
    printf("2.DELETE   ");
    printf("3.DISPLAY   ");
    printf("4.EXIT  " );
    printf("\n enter your choice of operation (1-4): ");
    scanf("%d", &choice);

    switch(choice)
    {
    case 1:

            insert();
            break;

    case 2:

            delete();
            break;

    case 3:

            display();
            break;

    case 4:
        printf("\n exiting....");
        return 0;

    default:
        printf("\n Invalid choice!! Please enter the valid choice ");
    }

}
return 0;


}



























#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
struct q
{
  int item;
  struct q *address;
};
typedef struct q *que;
int size=0;
que front=NULL,rear=NULL;
void insert(int cost)
{
  que temp;
  temp=(que)malloc(sizeof(que));
  temp->item=cost;
  temp->address=NULL;
  if(size < MAXSIZE)
  {
    if(front==NULL)
    {
      front=temp;
      rear=front;
    }
    else
    {
      rear->address=temp;
      rear=rear->address;
    }
    rear->address=front;
    size++;
  }
  else
  {
    printf("overflow\n");
  }
}

void delete()
{
  if(front==NULL)
  {
    printf("underflow\n");
  }
  else if(front ==rear)
  {
    front =NULL;
    rear=NULL;
  }
  else
  {
    que cur=front;
    front=front->address;
    free(cur);
    size--;
  }
}

void display()
{
  int pos=1;
  if (front==NULL)
  {
    printf("Nothing to print\n");
  }
  else
  {
    que cur=front;
    while(cur!=rear)
    {
      printf("%d=[%d]  ",pos,cur->item);
      cur=cur->address;
      pos++;
    }
    printf("%d=[%d]  ",pos,cur->item);
  }
  printf("\n");
}

void main()
{
  int ch,cost;
  for(;;)
  {
    printf("Enter your choice\n1.Insert\n2.Delete\n3.Display\n(press any other key to exit)\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: printf("Enter cost\n");
              scanf("%d",&cost);
              insert(cost);
              display();
              break;
      case 2: delete();
              display();
              break;
      case 3: display();
              break;
      default: exit(0);
    }
  }
}

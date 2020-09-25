#include <stdio.h>
#include <stdlib.h>
struct queue
{
  int item;
  struct queue *address;
};
typedef struct queue *queue;
queue front=NULL,rear=NULL;
void insert (int cost)   //checked
{
  queue node;
  node=(queue)malloc(sizeof(queue));
  node->item=cost;
  node->address=NULL;
  if(front==NULL)
  {
  node->address= front;
   front=node;
   rear=front;
  }
  else
  {
  rear->address=node;
  rear=rear->address;
  }
}
void delete()
{
  queue cur;
  if(front==NULL)
  printf("Nothing is present\n");
  else
  {
  cur=front;
  front=front->address;
  free(cur);
 }
}
void display()
{
  queue cur;
  int pos=1;
  if(front==NULL && rear==NULL)
  printf("Nothing to print\n");
  else
  cur=front;
  while(cur!=NULL)
  {
    printf("%d=[%d]\t",pos,cur->item);
    cur=cur->address;
    pos++;
  }
  printf("\n");
}
void queueoperations()
{
  int ch,cost;
  for(;;)
  {
  printf("Enter your choice\n");
  printf("1.enter\n2.move out \n3.display\n(Any other key to exit)\n");
  scanf("%d",&ch);
  switch(ch)
    {
      case 1:printf("enter the cost\n");
             scanf("%d",&cost);
             insert(cost);
             display();
             break;
      case 2:delete();
             display();
             break;
      case 3: display();
             break;                                                                         //forgot to put break;     error...runtime
      default:exit(0);
    }
  }
}
void main()
{
  queueoperations();
}

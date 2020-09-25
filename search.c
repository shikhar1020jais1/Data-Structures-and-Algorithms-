/*this is a new code similar to linkedlist with addition to search function
this function was in continues assessment 2 of data structures
but there we have to search and print only the position of first occurence of the number
but this code is slightly different from that
because in this we will search and print the position of all the occurence of the given number
now thw code begins
(everything is same only we will see the search part of the code)*/

#include <stdio.h>
#include <stdlib.h>
int size=0;
struct location
{
  int item;
  struct location *address;
};
typedef struct location *location;

location create()
{
  location newnode;
  newnode=(location)malloc(sizeof(struct location));
  return newnode;
}

location insertfront(location head,int cost)
{
  location temp;
  temp=create();
  temp->address=NULL;
  temp->item=cost;
  temp->address=head;
  head=temp;
  return head;
}

location deletefront(location head)
{
  location cur;
  if(head == NULL)
  printf("Empty\n");
  else
  {
  cur=head;
  head=head->address;
  free(cur);
  }
  return head;
}

void display(location head)
{
  location cur;
  int pos=1;
  if(head==NULL)
  printf("Nothing is there\n");
  else
  {
  cur=head;
  while(cur!=NULL)
  {
    printf("%d=[%d]\t",pos,cur->item);
    cur=cur->address;
    pos++;
  }
  printf("\n");
  }
}
//search function
int search (location head,int ele) // in this two parameters are required one is the list and another is the element to be searched
{
  location cur;   // first we will declare a temporary node for traversing the list
  int pos=1,flag=0; //declare pos as 1 as we will count the position
  cur=head; //store the head into the cur
  while(cur!=NULL)
  {
    if(cur->item == ele)
    {
      flag=1;
      printf("found at position %d\n",pos);
    }
    cur=cur->address;
    pos++;
  }
  if(flag==0)
  printf("Element not found\n");
  return 0;
}
void main()
{
  location head=NULL;
  int choice,cost,ele;
  for(;;)
  {
  printf("Enter your choice \n1.Insert Front \t2.Delete Front \t3.Display \t4.Search\n(press any other key to exit)\n");
  scanf("%d",&choice);
  switch (choice)
  {
    case 1:printf("Enter the cost\n");
           scanf("%d",&cost);
           head=insertfront(head,cost);
           display(head);
           break;
    case 2:head=deletefront(head);
           display(head);
           break;
    case 3:display(head);
           break;
    case 4:printf("Enter item to search\n");
           scanf("%d",&ele);
           search(head,ele);
           break;
    default:exit(0);
  }
}
}

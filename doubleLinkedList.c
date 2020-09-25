#include <stdio.h>
#include <stdlib.h>
//structure of a node
struct loc
{
  int item;
  struct loc *right;
  struct loc *left;
};
typedef struct loc *loc;
//to allot memory in a node
loc create()
{
  loc newnode;
  newnode=(loc)malloc(sizeof(struct loc));
  return newnode;
}
//to insert elements from front
loc insertfront(loc first,int cost)
{
  loc temp;
  temp=create();
  temp->item=cost;
  temp->left=NULL;
  if(first==NULL)
  {
    temp->right=NULL;
    first=temp;
  }
  else
  {
    temp->right=first;
    first->left=temp;
    first=temp;
  }
  return first;
}
//to insert element from last
loc insertlast(loc first,int cost)
{
  loc temp,cur;
  temp=create();
  temp->item=cost;
  if(first==NULL)
  {
    temp->left=NULL;
    temp->right=NULL;
    first=temp;
  }
  else
  {
    cur=first;
    while(cur->right!=NULL)
    {
      cur=cur->right;
    }
    cur->right=temp;
    temp->left=cur;
    temp->right=NULL;
  }
  return first;
}
//to insert at Position
loc insertpos(loc first,int cost,int pos)
{
  loc temp,cur,prv;
  int p=1;
  temp=create();
  temp->item=cost;
  if(first==NULL)
  {
    temp->left=NULL;
    temp->right=NULL;
    first=temp;
  }
  else
  {
    cur=first;
    while(cur->right!=NULL && p<pos)
    {
      prv=cur;
      cur=cur->right;
      p++;
    }
    prv->right=temp;
    temp->left=prv;
    temp->right=cur;
    cur->left=temp;
  }
  return first;
}
//to delete elements from front
loc deletefront(loc first)
{
  loc cur;
  if(first==NULL)
  {
    printf("Underflow\n");
  }
  else
  {
    cur=first;
    first=first->right;
    free(cur);
  }
  return first;
}
//to delete at Last
loc deletelast(loc first)
{
  loc cur,prv;
  if(first==NULL)
  {
    printf("Underflow\n");
  }
  else if(first->right==NULL)
  {
    first=NULL;
    free(first);
  }
  else
  {
    cur=first;
    while(cur->right!=NULL)
    {
      prv=cur;
      cur=cur->right;
    }
    prv->right=NULL;
    free(cur);
  }
  return first;
}
//to display the double linked list
loc deletepos(loc first,int pos)
{
  loc cur,prv;
  int p;
  if(first==NULL)
  {
    printf("Unerflow\n");
  }
  else
  {
    cur=first;
    while(cur->right!=NULL && p<pos)
    {
      prv=pos;
      cur=cur->address;
    }
    
  }
}
void display(loc first)
{
  loc cur;
  int p=1;
  if(first==NULL)
  {
    printf("Nothing to display\n");
  }
  else
  {
    cur=first;
    while(cur!=NULL)
    {
      printf("%d=[%d]  ",p,cur->item);
      cur=cur->right;
      p++;
    }
  }
  printf("\n");
}
//to display reverse linked list
void displayrev(loc first)
{
  loc cur;
  int p=1;
  if(first==NULL)
  {
    printf("Nothing to display\n");
  }
  else
  {
    cur=first;
    printf("The reverse is:\n");
    while(cur->right!=NULL)
    {
      cur=cur->right;
    }
    while(cur!=NULL)
    {
      printf("%d=[%d]  ",p,cur->item);
      cur=cur->left;
      p++;
    }
  }
  printf("\n");
}
//main function to call the above functions
void main()
{
   loc first=NULL;
   int ch,cost,pos;
   for(;;)
   {
     printf("Enter your choice:\nInsert: \t 1.Front \t 2.Last \t 3.Position\nDelete: \t 4.Front \t 5.Last \t 6.Position\nDisplay: \t 7.Front \t 8.Reverse\n(press any other key to exit)\n");
     scanf("%d",&ch);
     switch(ch)
     {
       case 1: printf("Enter cost\n");
               scanf("%d",&cost);
               first=insertfront(first,cost);
               display(first);
               break;
       case 2: printf("Enter cost\n");
               scanf("%d",&cost);
               first=insertlast(first,cost);
               display(first);
               break;
       case 3: printf("Enter cost\n");
               scanf("%d",&cost);
               printf("Enter position\n");
               scanf("%d",&pos);
               first=insertpos(first,cost,pos);
               display(first);
               break;
       case 4: first=deletefront(first);
               display(first);
               break;
       case 5: first=deletelast(first);
               display(first);
               break;
       case 7: display(first);
               break;
       case 8: displayrev(first);
               break;
       default: exit(0);
     }
   }
}

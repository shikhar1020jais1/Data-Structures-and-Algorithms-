#include<stdio.h>
#include<stdlib.h>
struct location
{
int item;
struct location *left;
struct location *right;
};

typedef struct location * LOCATION;

void display(LOCATION first)
{
  LOCATION cur;
  int pos=1;
  if(first==NULL)
   printf("list is empty\n");

  for(cur=first;cur!=NULL;cur=cur->right)
   {printf("%d = [%d]\n",pos,cur->item);
   pos++;
}}

void displayreverse(LOCATION first)
{
  LOCATION cur;
  if(first==NULL)
   printf("list is empty\n");

    for(cur=first;cur->right!=NULL;cur=cur->right);

    for(cur;cur!=NULL;cur=cur->left)
     printf("%d\n",cur->item);
}

LOCATION createlocation()
{
  LOCATION temp;
  temp=(LOCATION)malloc(sizeof(struct location));
  return(temp);
}

LOCATION insertfront(LOCATION first,int cost)
{
LOCATION temp;
temp=createlocation();
 temp->item=cost;
 if(first==NULL)
  {
    temp->left=NULL;
    temp->right=NULL;
    first=temp;
   }
   else
   {
    temp->right=first;
    first->left=temp;
    temp->left=NULL;
    first=temp;
   }
  return(first);
}

LOCATION deleteitem(LOCATION first, int element)
{
LOCATION cur,p,n;

 if(first==NULL)
  printf("Nothing to delete\n");
 else if(first->item==element)
  {
   cur=first;
   first=first->right;
   first->left=NULL;
   free(cur);
   }
 else
 {
  cur=first;
  while(cur!=NULL&&cur->item!=element)
  {
   cur=cur->right;
  }

   if(cur!=NULL)
    {
     if(cur->right==NULL)
     {
      p=cur->left;
      p->right=NULL;
      free(cur);
     }
     else
      {
       p=cur->left;
       n=cur->right;
       p->right=n;
       n->left=p;
      }
   }
   else
   {
    printf("No item to delete\n");
   }
 }
  return(first);
}


LOCATION insertinorder(LOCATION first,int element)
{
 LOCATION cur, p,n,temp;
 temp=createlocation();
 temp->item=element;
 if(first==NULL)
 {
  temp->left=NULL;
  temp->right=NULL;
  first=temp;
 }
 else if(first->item>element)
   {
    temp->left=NULL;
    temp->right=first;
    first->left=temp;
    first=temp;
   }
 else
  {
   cur=first;
    while(cur!=NULL && cur->item<element)
    {
      p=cur;
      cur=cur->right;
    }
    if(cur!=NULL)
    {
     p=cur->left;
     p->right=temp;
     temp->left=p;
     temp->right=cur;
     cur->left=temp;
    }
    else
    {
      p->right=temp;
      temp->left=p;
      temp->right=NULL;
    }
  }
return(first);
}
LOCATION deletefront(LOCATION first)
{
LOCATION cur;

 if(first==NULL)
  printf("Nothing to delete\n");
 else
  {
   cur=first;
   first->left=NULL;
   first=first->right;
   free(cur);
  }
 return(first);
}
LOCATION deletelast(LOCATION first)
{
LOCATION cur,prev;

 if(first==NULL)
  printf("Nothing to delete\n");
 else if(first->right==NULL)
     first=NULL;
 else
  {
    cur=first;
    while(cur->right!=NULL)
    {
     cur=cur->right;
    }
    prev=cur->left;
    prev->right=NULL;
    free(cur);
  }
 return(first);
}

LOCATION insertlast(LOCATION first,int cost)
{
LOCATION temp,cur;
temp=createlocation();
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
     temp->right=NULL;
   }
 return(first);
}

void main()
{
   LOCATION first=NULL;
   int cost,choice,element;
    for(;;)
    {
      printf("Enter the Choice\n");
      printf("1: Insert front \t 2: Display \t 3: Display reverse\n");
      printf("4: Insert Last \t 5: Insert in ascending order \n");
      printf("6: delete front\t  7: Delete last \t  8: Delete item\n");
      scanf("%d",&choice);
      switch(choice)
       {
        case 1: printf("Enter the 1st cost to insert\n");
        	scanf("%d",&cost);
	        first=insertfront(first,cost);
	        break;
	case 2: display(first);
                  break;
        case 3: displayreverse(first);
                 break;
        case 4: printf("Enter the cost to insert\n");
        	scanf("%d",&cost);
	        first=insertlast(first,cost);
	        break;
        case 5: printf("Enter the cost to insert\n");
        	scanf("%d",&cost);
	        first=insertinorder(first,cost);
	        break;
        case 6: first = deletefront(first);
                printf("the list after deleting\n");
                display(first);
                break;
        case 7: first = deletelast(first);
                printf("the list after deleting\n");
                display(first);
                break;
        case 8: printf("Enter the item to delete\n");
                 scanf("%d",&element);
                first=deleteitem(first,element);
	        printf("the list after deleting\n");
                display(first);
                break;
       default : exit(0);
       }
   }
}

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10 // Maximum size of stack
typedef int shirtnum;
typedef char shirtcolor;
struct stacklocation
{
	shirtnum sn;
	shirtcolor sc;
	struct stacklocation *link;
};
typedef struct stacklocation *LOCATION;
int s=0;
LOCATION push(shirtnum snum,shirtcolor scolor,LOCATION top)
{
	LOCATION n=(LOCATION)malloc(sizeof(LOCATION));
	n->link=NULL;
	n->sn=snum;
	n->sc=scolor;
   if(s<MAX_SIZE)
	 {
		n->link=top;
		top=n;
		s++;
	 }
	 else
	printf("Stack full\n");

	return(top);

}
LOCATION pop(LOCATION top)
{
	if(top!=NULL)
	{
		LOCATION cur=top;
		printf("the deleted item is %d\n",cur->sn);
		top=top->link;
		free(cur);
		s--;
	}
	else
	 printf("stack empty\n");

	return(top);

}
void display(LOCATION top)
{
	LOCATION cur;
	if(top==NULL)
		printf(" No shirt leftout in the Cupboard\n");
	else
	{
		cur=top;
	  while(cur!=NULL)
		{
			printf("Item = [%d]\tCOLOR = [%c]\n",cur->sn,cur->sc);

			cur=cur->link;
		}
	}
}
void stackoperation(LOCATION top)
{
	int choice;
	shirtnum snum;
	shirtcolor scolor;
	for(;;)
	{
		printf("Enter the Choice\n");
		printf("1: Priya Keeps Shirt \t 2: Hari take Shirt \t 3:Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("enter the shirt no\n");
						 scanf("%d",&snum);
						 printf("enter the shirt color\n");
						 scanf(" %c",&scolor);
						  top=push(snum,scolor,top);
			 			 display(top);
			       break;
			case 2:top=pop(top);
		      	 display(top);
						 break;
			case 3:display(top);
					   break;
			default: exit(0);
		}
	}
}
void main()
{
	LOCATION top=NULL;
	stackoperation(top);
}

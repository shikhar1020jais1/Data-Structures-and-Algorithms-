//to check whether the given string has equal number of characters
//Using Stack
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 10
struct stack
{
	char item;
	struct stack *link;
};
typedef struct stack *LOCATION;
int s=0;
LOCATION push(char para,LOCATION top)
{
	if(s<MAX_SIZE)
  {
  LOCATION n=(LOCATION)malloc(sizeof(LOCATION));
	n->link=NULL;
	n->item=para;
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
		top=top->link;
		free(cur);
    s--;
	}
	else
	 printf("stack empty\n");
	return(top);

}
void stackoperation(LOCATION top)
{
	int choice;
	char para[50];
  gets(para);
  int i,length;
  length=strlen(para);
  i=0;
  while(i<length)
  {
    if(para[i]=='a' )
    {
		if(s<MAX_SIZE)
    top=push(para[i],top);
		else
		break;
    i++;
    }
    else if(s>0)
    {
    top=pop(top);
    i++;
    }
    else
    break;
    }
    if(i==length && s==0)
    printf("BALANCED\n");
    else
    printf("NOT BALANCED\n");
  }
void main()
{
	LOCATION top=NULL;
	stackoperation(top);
}

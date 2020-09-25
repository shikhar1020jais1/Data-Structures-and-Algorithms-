#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 1000
struct stack
{
	char item;
	struct stack *link;
};
typedef struct stack *LOCATION;
int s;
LOCATION push(char para,LOCATION top)
{
	if(s<=MAX_SIZE)
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
int stackoperation(LOCATION top,char para[])
{
  int i,length;
  length=strlen(para);
  i=0;
  while(i<length)
  {
    if(para[i]=='(' || para[i]=='[' || para[i]=='{')
    {
    top=push(para[i],top);
    i++;
    }
    else if(s>0 )
    {
        if((para[i]=='}' && top->item=='{') || (para[i]==']' && top->item=='[') || (para[i]==')' && top->item=='('))
        {
            top=pop(top);
            i++;
        }
        else
        {
            s=-1;
            break;
        }
    }
    }
    if(i==length && s==0)
    printf("YES\n");
    else
    printf("NO\n");
    return 1;
}
int main()
{   
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    char para[50];
    s=0;
    scanf("%s",para);
	LOCATION top=NULL;
	stackoperation(top,para);
    }
return 1;
}

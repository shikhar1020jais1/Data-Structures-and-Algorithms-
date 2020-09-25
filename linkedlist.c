#include<stdio.h>  //input/output
#include<stdlib.h> //for Library function

int size = 0;    //global

struct location //to create a structure of a node
{
	int item;
	struct location *address;
};

typedef struct location *LOCATION;

LOCATION create()
{
	LOCATION newnode;
	newnode = (LOCATION)malloc(sizeof(struct location)); //to allcocate space for a newnode

	return(newnode);
}
// to insert a item to a particular posiition
LOCATION insert_POS(LOCATION head, int cost, int in_pos)
{
	LOCATION node=create(),current,prv=NULL; // again new temporary variable created , and current , lets take prev == NULL
	int pos = 1;     //initialise pos=1

	if(in_pos > size)     //check whether pos is not greater then size
	{
		printf("Invalid Position\n");    //if yes  invalid position
	}
	else                        //if no
	{
		current = head;						// again store the value of head into current

		while(current->address != NULL && pos < in_pos)      //now a loop to increment the node with the incrementation of position.. 1 node before the given position
		{
			prv = current;                     //now store prev = current
			current = current->address;				// and increment the current
			in_pos++;													//increment the position
		}

		prv->address = node;               //now point the address of prev towards node
		node->address = current;					//and address of node towards current
		node->item = cost;								// and store the cost into the item part of node
		size++;														// increment the size
		return(head);
	}
}
// to insert elements from Front
LOCATION insert_FRONT(LOCATION head, int cost)
{
    LOCATION node; //temporary node
    node = create();  //calling create function to allocate space in node

    node->item = cost;     //to store the cost into the item part of the node
    node->address = head; // to point the address of node to the head

    head = node; // to store the temporary node into the head
    size++; // increase the size of the node
    return head;


}
// to insert the item from Last
LOCATION insert_LAST(LOCATION head, int cost)
{
	LOCATION node = create(),current; // one temporary variable node and one pointing variable current

	if(head == NULL)      // to check whether any node is already present or not
	{                      //if not then copy the #front code
		node->item = cost;
		node->address = head;
		head = node;
		size++;
		return head;
	}
	else                        //if yes
	{
		current = head;           // then first store the head value into current

		while(current->address != NULL)    //then start at loop to check whether the address of current is null or not .....
		{
			current = current->address;      // this will take the current to the last node
		}
												  							// now after reaching to the last node
		node->item = cost;                  //again we will store the cost value into the item part of node
		node->address = NULL;								// and address part to NULL ,as it is the last node its address will be null
		current->address = node;						// and we will point the address of current towards the temporary node
		size++;															// increment the size
		return(head);
	}

}
// display the list
void display(LOCATION head)
{
	LOCATION current;
	int pos = 1;         //again position = 1


	if(head == NULL)      // if nothing is present
	{
		printf("List is empty\n");   // display empty list
	}
	else        //if present
	{
		printf("List Size = %d\n",size);  											//display the list size
		current = head;																					// then store the value of head into current as before
		while (current != NULL)																	//while current is not equal to null
		{
		    printf("%d->[%d], ",pos, current->item);            //display the item
		    current = current->address;													// incrementation of node
		    pos++;																							//increment the postion
		}
		printf("\n");																						//after printing print a new line
    }
}

//to delete a particular item
LOCATION delete(LOCATION head, int del_item)
{
	LOCATION current,prv;             													//again prv and current

	if(head == NULL)                 														// check head is NULL or not
	{
		printf("Nothing to delete, List is empty\n");    					//if NULL display
	}
	else																												//if not
	{
		if(head->item == del_item)                         				//then check wheather head of item is equal to the item which is to be deleted or not
		{
			printf("Item %d has been deleted\n",head->item);    		//if yes copy the delete_FRONT part
			current = head;
			head = head->address;
			free(current);
			size--;
			return(head);

		}
		else																												//if no
		{
			prv = NULL;																								// then store prev = null
			current = head;																						//current as head

			while(current != NULL && current->item != del_item)       //then check to conditions current for null and current of item for that item to be delete
			{
				prv=current;                                             //if not then prv as current
				current = current->address;																// and current is incremented
			}
			if(current == NULL)																					//check for current is == null
			{
				printf("Item not found in the list\n");											//if yes display
			}
			else																													// if not
			{
				printf("Item %d has been deleted\n",current->item);         //display the item to the deleted
				prv->address = current->address;														// so point the address of prev to the address of current
				free(current);																							// and free the current
				size--;																											// decrement the size
			}

			return(head);																									//return head
		}

	}
}



//to delete at last
LOCATION delete_LAST(LOCATION head)
{
	LOCATION current,prv;  														//again current and prv as before

	if(head == NULL)      														 // check anything is present or not
	{
		printf("Nothing to delete, List is empty\n");   //if yes display
	}

	else																							//if no then
	{
		prv = NULL;                                   // store prev as null as before
		current = head;																//head into current

		while(current->address != NULL)								// while loop to take the current to the last node
		{
			prv = current;															//prv as current
			current = current->address;									// increment the current
		}

		printf("List item %d has been deleted\n",current->item); //display the item to be deleted
		prv->address = NULL;																		//store the address of prev as NULL
		free(current);                                          //free the current
		size--;																									//decrement the size

	}

	display(head);																					//display and return the head

	return(head);

}
//to delete from Front
LOCATION delete_FRONT(LOCATION head)
{
	LOCATION current;																					//new pointing node current

	if(head == NULL)																					//if  no node is present
	{
		printf("Nothing to delete, List is empty\n");						//display no node is present or list is empty
	}
	else                                                      // if present
	{
		printf("Item %d has been deleted\n",head->item);			  //display the item which is to be deleted
		current = head;																					//then again store head into current
		head = head->address;																		//and increment the head
		free(current);																					// the use the free function to remove the space from current
		size--;																									//decrement the size
		display(head);																					//display the head and return
		return(head);

	}
}



//main function to call all the above function
void main()
{
	LOCATION head = NULL;      							 									// declare a node
	int cost, choice,del_item,ins_pos;   											// then pos choice and all the suitable identifier

	for(;;)    																								// a infinite loop
	{

		printf("Enter your choice\n1. Insert At Position\n2. Insert At Front\n3. Insert At Last\n4. Delete An Item \n5. Delete At Last\n 6. Delete At Front\n7. Display List\n Press Any other key to exit\n");
		scanf("%d",&choice);   																			// various options as input

		switch(choice)         																			 // switch to go through the options
		{
			case 1: printf("Enter the cost of the item purchased and the position of insertion\n");
					scanf("%d%d",&cost,&ins_pos);
					head = insert_POS(head,cost,ins_pos);             // to call the insert_POS function
					display(head);
					break;

			case 2: printf("Enter the cost of the item purchased\n");
					scanf("%d",&cost);
					head = insert_FRONT(head,cost);								// to call the insert_FRONT function
					display(head);
					break;

			case 3: printf("Enter the cost of the item purchased\n");
					scanf("%d",&cost);
					head = insert_LAST(head,cost);									// to call the insert_LAST function
					display(head);
					break;

			case 4: printf("Enter the item to delete\n");
					scanf("%d",&cost);
					head = delete(head,cost);											// to call the Delete function
					display(head);
					break;

			case 5: head = delete_LAST(head);                // to call the delete_LAST function
					break;

			case 6: head = delete_FRONT(head);              // to call the delete_FRONT function
					break;

			case 7: display(head);                         // to call the display function
					break;

			default: exit(0);

		}
	}

}

/*Queue implementation using array*/
#include<stdio.h>
#include<stdlib.h>

struct node {
		int data;
		struct node *next;
	    }; 
		struct node *front=NULL; struct node *rear=NULL;

void enqueue(int value)
{
   struct node *input;
   input=(struct node*)malloc(sizeof(struct node));
   input->data=value;
   input->next=NULL;
   if(front==NULL)
      front=rear=input;
   else
   {
      rear->next=input;
      rear=input;
   }
   printf("Inserted element is %d\n",input->data);
}

void dequeue()
{
   if(front==NULL)
		printf("Queue is empty\n");
   else
   {
      struct node *del=front;
      front=front->next;
      printf("Deleted element is %d\n",del->data);
      free(del);
   }
}

void display()
{
  if(front==NULL)
		printf("Queue is empty\n");
   else
   {
      struct node *temp=front;
      while(temp->next!=NULL)
      {
	 	printf("|___%d___",temp->data);
	 	temp=temp->next;
      }
      printf("|___%d___|\n",temp->data);
   }
}

void main()
{
	while(1)
	{
		int queue,ch,entry,i;
		printf("\n1.Enqueue\t\t2. Dequeue\t\t3. Display\t\t4.Exit\t");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{	
			case 1:
			{
				printf("Enter element: ");
				scanf("%d",&entry);
				enqueue(entry);
				break;
			}
					
			case 2:
			{
				dequeue();
				break;
			}
			
			case 3:
			{
				display();
				break;
			}
	
			case 4:
			{
				printf("Succesfully exiting program \n");
				exit(0);
			}
			
			default:
			{
				printf("\nError,wrong choice input");
				printf("\n");
				break;
			}
		}
	}
}

/*Implementation of basic linked list: Insert, Display and Count*/
#include<stdio.h>
#include<stdlib.h>

void main()
{
	struct node
	{
		int data;
		struct node *next;
	};
	struct node *head=NULL,*pos=NULL,*tail=NULL;
	
	int ch,entry,count=0;
	while(1)
	{
		printf("\n1:Insert\t\t2:Display\t\t3:Count\t\t4:Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			{
				printf("\nEnter data: ");
				scanf("%d",&entry);
				if(head==NULL)
				{
					head=(struct node*)malloc(sizeof(struct node));
					head->data=entry;
					pos=head;
					tail=head;
				}
				else
				{
					tail->next=(struct node*)malloc(sizeof(struct node));
					tail=tail->next;
					tail->data=entry;
				}
				printf("Data succesfully stored\n");
				break;
			}
			
			case 2:
			{
				pos=head;
				printf("\nElements are: ");
				while(pos!=NULL)
				{
					printf("%d ",pos->data);
					pos=pos->next;
				}
				printf("\n");
				break;
			}
			
			case 3:
			{
			
				pos=head;
				count=0;
				while(pos!=NULL)
				{
					pos=pos->next;
					count++;
				}
				
				printf("\nElement count is: %d",count);
				printf("\n");
				break;
			}
			
			case 4:
			{
				printf("Goodbye\n");
				exit(0);
			}
			
			default:
			{
				printf("Error, Wrong input\n");
			}
		}
	}
}
			
					

/*Menu Implementation of singly linked list: Insert, Delete, Search and Traverse*/
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
	
	int ch,entry,count=0,find,i;
	while(1)
	{
		printf("\n1:Insert\t\t2:Delete\t\t3:Search\t\t4:Traverse\t\t5:Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			{
				printf("Enter data: ");
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
				struct node *temp=head;
				
				if(head==NULL)
				{
					printf("Nothing to delete");
					break;
				}
				
				printf("Enter position of data: ");
				scanf("%d",&entry);
				count=0;pos=head;
				while(pos!=NULL)
				{
					pos=pos->next;
					count++;
				}
				
				if(entry>count+1)
				{
					printf("Out of range ");
					break;
				}
				
				else if(entry==0)
				{
					head=head->next;
					temp->next=NULL;
					free(temp);
					break;
				}
				
				else if(entry==count-1)
				{
					for(i=0;i<entry-1;i++)
					{
						temp=temp->next;
					}
					tail=temp;
					temp=tail->next;
					tail->next=NULL;
					printf("Deleted element is %d",temp->data);
					free(temp);
					break;
				}
				else
				{
					for(i=0;i<entry-1;i++)
					{
						temp=temp->next;
					}
					
					struct node *del=temp->next;
					temp->next=temp->next->next;
					del->next=NULL;
					free(del);
				}
				break;
			}
			
			case 3:
			{
				pos=head;
				count=0;
				printf("Enter element to search: ");
				scanf("%d",&find);
				while(pos!=NULL)
				{
					if(pos->data==find)
					{
						printf("Element found at node %d",count);
						break;
					}
					else
					{
						pos=pos->next;
						count++;
					}
				}
				if(pos==NULL)
				{
					printf("Element not found");
				}	
				printf("\n");
				break;
			}
			
			case 4:
			{
				pos=head;
				
				if(pos==NULL)
				{
					printf("Nothing to print");
				}
				else
				{
					printf("\nElements are: ");
					while(pos!=NULL)
					{
						printf("%d ",pos->data);
						pos=pos->next;
					}
				}
				printf("\n");
				break;
			}
			
			case 5:
			{
				printf("Succesfully exiting program\n");
				exit(0);
			}
			
			default:
			{
				printf("Error, Wrong input\n");
			}
		}
	}
}
			
					

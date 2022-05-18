/*Implementation of basic linked list: Insert, Display, Count, Search, Random Populate and Time Complexities*/
/*Change number in line 25 to specify size*/
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

void main()
{
	struct timeval t0;
   	struct timeval t1;
  	float elapsed;
	
	struct node
	{
		int data;
		struct node *next;
	};
	struct node *head=NULL,*pos=NULL,*tail=NULL;
	
	int ch,number=10,count=0,find,flag=0,j;
	printf("\nRandom Population size is set at: %d",number);
	while(1)
	{
		printf("\n1:Insert\t\t2:Display\t\t3:Count\t\t4:Search an element\t\t5:Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			{
				gettimeofday(&t0, NULL);
				srand(time(0));
				for(j=0;j<number;j++)
				{
					
					if(head==NULL)
					{
						
						head=(struct node*)malloc(sizeof(struct node));
						head->data=rand()%100;
						pos=head;
						tail=head;
					}
					else
					{
						
						tail->next=(struct node*)malloc(sizeof(struct node));
						tail=tail->next;
						tail->data=rand()%100;
					}
				}
				printf("%d Data elements succesfully stored in linked list\n",number);
				gettimeofday(&t1, NULL);
				elapsed = timedifference_msec(t0, t1);
			   	printf("Insert Code executed in %f milliseconds.\n", elapsed);
				break;
			}
			
			case 2:
			{
				gettimeofday(&t0, NULL);
				pos=head;
				printf("\nElements are: ");
				while(pos!=NULL)
				{
					printf("%d ",pos->data);
					pos=pos->next;
				}
				printf("\n");
				gettimeofday(&t1, NULL);
				elapsed = timedifference_msec(t0, t1);
			   	printf("Display Code executed in %f milliseconds.\n", elapsed);
				break;
			}
			
			case 3:
			{
			
				gettimeofday(&t0, NULL);
				pos=head;
				count=0;
				while(pos!=NULL)
				{
					pos=pos->next;
					count++;
				}
				
				printf("\nElement count is: %d",count);
				printf("\n");
				gettimeofday(&t1, NULL);
				elapsed = timedifference_msec(t0, t1);
			   	printf("Count Code executed in %f milliseconds.\n", elapsed);
				break;
			}
			
			case 4:
			{
				gettimeofday(&t0, NULL);
				pos=head;
				count=0;
				printf("\nEnter element to search: ");
				scanf("%d",&find);
				while(pos!=NULL)
				{
					if(pos->data==find)
					{
						printf("\nElement found at node %d",count+1);
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
					printf("\nElement not found");
				}	
				printf("\n");
				gettimeofday(&t1, NULL);
				elapsed = timedifference_msec(t0, t1);
			   	printf("Search Code executed in %f milliseconds.\n", elapsed);
				break;
			}
				
			
			
			case 5:
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
			
					

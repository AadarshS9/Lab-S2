/*Binary Search*/
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int array[100];

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}


int main()
{
    struct timeval t0;
    struct timeval t1;
    float elapsed;
    
    while(1)
    {
		int i,ch,low,mid,high;
		long int size,limit,key;
		printf("\n1.Create list size and limit\t\t2.Generate Random Numbers\t\t3. Search\t\t4.Exit\t");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			{	
				printf("Enter number of Elements: ");
				scanf("%d",&size);
				long int array[size];
				printf("Enter Upper limit in place values: ");
				scanf("%ld",&limit);
				break;
			}
			
			case 2:
			{
				
				int num=size;
				int j,x,y,temp;
				srand( (unsigned) time(NULL) * getpid());
				gettimeofday(&t0, NULL);
				if(array != NULL)
				{
					for(j = 0; j < num; j++)
					{
						array[j] = rand()%limit;
					}
				}
				gettimeofday(&t1, NULL);
        		elapsed = timedifference_msec(t0, t1);
				
				for(x = 0; x < num - 1; x++)
				{       
					for(y = 0; y < num - x - 1; y++)
					{          
						if(array[y] > array[y + 1])
						{               
						    temp = array[y];
						    array[y] = array[y + 1];
						    array[y + 1] = temp;
						}
					}
				}
				
				for(j = 0; j < num; j++)
				{
					printf("%ld\n",array[j]);
				}				
				printf("Random Generation code executed in %f milliseconds.\n", elapsed);
				break;
			}
			
			
				
			case 3:
			{	  	 
				printf("Enter element to search for: ");
				scanf("%ld",&key);
				low=0;high=size-1;mid=(high+low)/2;
				gettimeofday(&t0, NULL);
				while (low<=high)
				{
					if(array[mid]<key)
						low=mid+1;
						
					else if (array[mid]==key) 
					{
						printf("%ld found at position %d\n",key,mid);
					break;
					}
					
					else
						high=mid-1;
						
					mid=(low+high)/2;
					}
					gettimeofday(&t1, NULL);
        			elapsed = timedifference_msec(t0, t1);
					
					
					if(low>high)
						printf("%ld not present\n",key);
				
				printf("Binary Search code executed in %f milliseconds.\n", elapsed);
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

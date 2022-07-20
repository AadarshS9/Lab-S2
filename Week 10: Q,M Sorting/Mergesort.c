// Program - Merge Sort
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
int array[10000];
void mergesort (int [], int, int);
int  partition(int[], int, int);
void swap(int*, int*);
float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

void merge(int array[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
		L[i] = array[l + i];
	for (j = 0; j < n2; j++)
		R[j] = array[m + 1+ j];

	i = 0;
	j = 0;
	k = l;
	
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		array[k] = L[i];
		i++;
		k++;
	}	

	while (j < n2)
	{
		array[k] = R[j];
		j++;
		k++;
	}
}



void mergesort(int array[], int l, int r)
{
    int h=r-l;
    if (l < r) {
        int m = l+h/2;
        mergesort(array, l, m);
        mergesort(array, m + 1, r);
        merge(array, l, m, r);
    }
}


int main()
{
    struct timeval t0;
    struct timeval t1;
    float elapsed;
    
	int i,key,ch;
	long size,limit;
	printf("Enter number of Elements: ");
	scanf("%ld",&size);
	int array[size];
	printf("Enter upper limit in terms of place Values: ");
	scanf("%ld",&limit);
	
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
	printf("\n");
	printf("List of Numbers\n");
	for(j = 0; j < num; j++)
	{
		printf("%d\n",array[j]);
	}				
	printf("Random Generation code executed in %f milliseconds.\n", elapsed);
    printf("\n");
    
    gettimeofday(&t0, NULL);
    mergesort(array,0,size - 1);
    gettimeofday(&t1, NULL);
    elapsed = timedifference_msec(t0, t1);
    printf("Merge Sorted List of Numbers\n");
	for(j = 0; j < num; j++)
	{
		printf("%d\n",array[j]);
	}
   printf("Merge Sort Code executed in %f milliseconds.\n", elapsed);
}



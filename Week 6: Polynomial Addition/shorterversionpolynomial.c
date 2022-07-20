/*Polynomial Addition using Linked List*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int coefficient;
	int power;
	struct node* next;
}; struct node *input1=NULL,*input2=NULL,*sum=NULL;

void create(struct node *input,int maxp)
{	
	int size,i;
	for(i=maxp;i>0;i--)
	{
		printf("Kindly Enter Term x^%d Coefficient: ",i);
		scanf("%d",&input->coefficient);
		input->power=i;
		input->next=(struct node*)malloc(sizeof(struct node));
		input=input->next;
		input->next=NULL;
	}
}

void display(struct node *input)
{	
		while(input->next!=NULL)
		{
			printf(" %dx^%d ",input->coefficient,input->power);
			input=input->next;
			if (input->next!=NULL)
				printf("+");
		}
}


void addition(struct node *input1,struct node *input2,struct node *sum)
{
	while(input1->next &&  input2->next)
	{
		if(input1->power > input2->power)
		{
			sum->power=input1->power;
			sum->coefficient=input1->coefficient;
			input1=input1->next;
		}
		
		else if(input1->power < input2->power)
		{		
			sum->power=input2->power;
			sum->coefficient=input2->coefficient;
			input2=input2->next;
		}
		
		else
		{
			sum->power=input1->power;
			sum->coefficient=input1->coefficient + input2->coefficient;
			input1=input1->next;
			input2=input2->next;
		}
		sum->next=(struct node *)malloc(sizeof(struct node));
		sum=sum->next;
		sum->next=NULL;
	}

	while(input1->next || input2->next)
	{
		if(input1->next)
		{
			sum->power=input1->power;
			sum->coefficient=input1->coefficient;
			input1=input1->next;
		}

		if(input2->next)
		{
			sum->power=input2->power;
			sum->coefficient=input2->coefficient;
			input2=input2->next;
		}
		sum->next=(struct node *)malloc(sizeof(struct node));
		sum=sum->next;
		sum->next=NULL;
	}
}

void sort(struct node *input)
{
	struct node *i,*j;
	int temp;
	for(i=input;i->next!=NULL;i=i->next)
	{
		for(j=i->next;j!=NULL;j=j->next)
		{
    		if(i->power <= j->power)
    		{
				temp=i->power;
				i->power=j->power;
				j->power=temp;
				temp=i->coefficient;
				i->coefficient=j->coefficient;
				j->coefficient=temp;
    		}
		}
	}
}

void main()
{
	input1=(struct node*)malloc(sizeof(struct node));
	input2=(struct node*)malloc(sizeof(struct node));
	sum=(struct node*)malloc(sizeof(struct node));
	
	int maxp;
	printf("Enter maximum power: ");
	scanf("%d",&maxp);
	
	printf("\nPolynomial expression 1 \n");
	create(input1,maxp);
	sort(input1);
	printf("Polynomial expression 1:   ");
	display(input1);
	printf("\n");

	printf("\nPolynomial expression 2 \n");
	create(input2,maxp);
	sort(input2);
	printf("Polynomial expression 2:   ");
	display(input2);
	printf("\n");

	addition(input1,input2,sum); 
	printf("\nSum is:   ");
	display(sum); 
	printf("\n");               		
           
}

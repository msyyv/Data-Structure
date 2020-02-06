#include<stdio.h>
#include<conio.h>

struct dlinklist
{
	int info;
	struct dlinklist *next,*prev;
};

struct dlinklist *head='\0',*tail='\0';
int nor=0;
void insert(int x)
{
	struct dlinklist *temp,*temp1;
	temp=head;
	 if(temp=='\0')
	 {
		temp=(struct dlinklist *)malloc(sizeof(struct dlinklist));
		printf("\n you are trying to insert first node:");
		temp->next='\0';
		temp->prev='\0';
		temp->info=x;
		tail=temp;
		nor++;
		head=temp;
		delay(600);
		printf("\n node inserted");
	 }
	 else
	 {
		temp1=(struct dlinklist *)malloc(sizeof(struct dlinklist));
		while(temp->next!='\0')
		{
		 temp=temp->next;

		}
		temp1->next='\0';
		temp1->prev=temp;
		temp->next=temp1;
		tail=temp1;
		nor++;
		temp1->info=x;
		delay(500);
		printf("\n new node inserted successfully");
	 }

}
void mid_insert(int pos)
{
	struct dlinklist *temp,*temp1;
	int i=1,num=0;
	temp=head;
	while(i<(pos-1))
	{
	     temp=temp->next;
	     i++;
	}
	printf("\n enter value to insert: ");
	scanf("%d",&num);
	if(pos>nor)
	{
		printf("\n position is more than list size: ");

	}
	else if(temp=='\0')
	{
		delay(500);
	 printf("\n list is empty first call insert method");
	}
       else if(temp->next=='\0')
       {
	      printf("\n you are inserting last node:");
	      temp1=(struct dlinklist *)malloc(sizeof(struct dlinklist));
	      temp1->next='\0';
	      temp->next=temp1;
	      temp1->prev=temp;
	      temp->info=num;
	      tail=temp1;
       }
       else if(temp->prev=='\0')
       {
	//first node insertion
	printf("\n you are trying to insert at first posotion ");
	temp1=(struct dlinklist *)malloc(sizeof(struct dlinklist));
	temp1->info=num;
	temp1->next=temp;
	temp->prev=temp1;
	head=temp1;
	temp1->prev='\0';
	delay(500);
	printf("\n node inserted successfully:");

       }
       else
       {
	temp1=(struct dlinklist *)malloc(sizeof(struct dlinklist));
	temp1->info=num;
	temp1->next=temp->next;
	temp->next->prev=temp1;
	temp->next=temp1;
	temp1->prev=temp;
	delay(500);
	printf("\n node inserted successfully");
       }
}

void delete1(int pos)
{
	struct dlinklist *temp,*temp1;
	int i=1;
	temp=head;
	if(pos>nor)
	{
		delay(500);
		printf("\n positon is out of list length");

	}
	else if(pos<1)
	{
		delay(500);
		printf("\n -ve or 0 position not allowed");

	}
	else
	{
	   while(i<(pos-1))
	   {
		temp=temp->next;
		i++;
	   }

	   if(temp->next=='\0')
	   {
		printf("\n you are deleting last node:");
		temp1=temp->prev;
		temp1->next='\0';
		free(temp);
		tail=temp1;
		delay(500);
		printf("\n last node deleted successfully");

	   }
	   else if(temp->prev=='\0')
	   {
		printf("\n you are about to delete first node");
		head=temp->next;
		head->prev='\0';
		free(temp);
		delay(500);
		printf("\n node deleted successfully");

	   }
	   else
	   {
	     temp1=temp->next;
	     temp1->next->prev=temp;
	     temp->next=temp1->next;
	     free(temp1);
	     delay(500);
	     printf("\n node at %d position deleted",i+1);

	   }  //else
       }//else
}



void disp()
{
	struct dlinklist *temp='\0';
	int x=1;
	temp=head;
	while(temp!='\0')
	{
		printf("\n %d.) %d",x++,temp->info);
		temp=temp->next;

	}
}


void last_disp()
{
	struct dlinklist *temp='\0';
	int x=1;
	temp=tail;
	while(temp!='\0')
	{
		printf("\n %d.) %d",x++,temp->info);
		temp=temp->prev;

	}
}


void main()
{

    int num,pos;
    char ch;
    clrscr();
    do
    {
	printf("\n enter number: ");
	scanf("%d",&num);
	insert(num);
	delay(600);
	 printf("\n press y to insert more: ");
	 ch=getche();

    }while(ch=='y');

	disp();

	printf("\n displaying from last");
	last_disp();

	do
	  {
	printf("\n enter position to insert: ");
	scanf("%d",&pos);
	mid_insert(pos) ;
	delay(600);
	 printf("\n press y to insert more: ");
	 ch=getche();

    }while(ch=='y');

	printf("\n after inserting new node list is");
	 disp();
	printf("\n displaying from last");
	last_disp();
	do
    {
	printf("\n enter positon to delete ");
	scanf("%d",&pos);
	delete1(pos);
	delay(600);
	 printf("\n press y to delete more: ");
	 ch=getche();

    }while(ch=='y');
    printf("\n after deleting node list is");
	 disp();
	printf("\n displaying from last");
	last_disp();

     getch();

}
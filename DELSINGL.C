struct slist
{
	int info;
	struct slist *next;

};
	struct slist *head='\0';


void insert(int n)
{
	struct slist *temp,*temp1;
	temp=head;
	if(temp=='\0')
	{
		temp=(struct slist *)malloc(sizeof(struct slist));
		temp->info=n;
		temp->next='\0';
		head=temp;
		printf("\n node inserted successfully");

	}
	else
	{
		while(temp->next!='\0')
		{
			temp=temp->next;
		}
		temp1=(struct slist *)malloc(sizeof(struct slist ));
		temp1->info=n;
		temp1->next='\0';
		temp->next=temp1;
		printf("\n node created successfully");
	}


}
void disp()
{
	struct slist *temp;
	temp=head;
	while(temp!='\0')
	{
	 printf("\n %d",temp->info);
	 temp=temp->next;
	}
}

void del(int pos)
{
	struct slist *temp,*temp1;
	int i=1;
	temp=head;
	if(temp=='\0')
	{
	 printf("\n there is no element in list");

	}
	else
	{
		while(i<pos)
		{
		  temp1=temp;
		  temp=temp->next;
		  i++;
		}
	       if(temp->next=='\0')
	       {
		       temp1->next='\0';
		       free(temp);
		       printf("\n last node ddleted");

	       }
	       else if(temp==head)
	       {
		    head=temp->next;
		    free(temp);
		    printf("\n fast node deleted");


	       }
	       else
	       {
		    temp1->next=temp->next;
		    free(temp);
		    printf("\n node deleted");


	       }
	}
}

void main()
{
	int num;
	char ch;
	clrscr();
	do
	{
	   printf("\n enter element to insert::");
	   scanf("%d",&num);
	   insert(num);
	   printf("\n press y to insert more::");
	   ch=getch();
	}while(ch=='y');
	printf("\n list before deletion::");
	disp();
	do
	{
	   printf("\n enter position to delete::");
	   scanf("%d",&num);
	   del(num);
	   printf("\n press y to delete more::");
	   ch=getch();
	}while(ch=='y');
	printf("\n list after deletion::");
	disp();
	getch();

}
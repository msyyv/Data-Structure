struct dlist
{
	int info;
	struct dlist *next,*prev;

};
	struct dlist *head='\0',*tail='\0';


void insert(int n)
{
	struct dlist *temp,*temp1;
	temp=head;
	if(temp=='\0')
	{
		temp=(struct dlist *)malloc(sizeof(struct dlist));
		temp->info=n;
		temp->next='\0';
		temp->prev='\0';
		head=temp;
		tail=temp;
		printf("\n node inserted successfully");

	}
	else
	{
		while(temp->next!='\0')
		{
			temp=temp->next;
		}
		temp1=(struct dlist *)malloc(sizeof(struct dlist ));
		temp1->info=n;
		temp1->next='\0';
		temp->next=temp1;
		temp1->prev=temp;
		tail=temp1;
		printf("\n node created successfully");
	}


}
void disp()
{
	struct dlist *temp;
	temp=head;
	while(temp->next!='\0')
	{
	 printf("\n %d",temp->info);
	 temp=temp->next;
	}
}

void dodd()
{
	struct dlist *temp,*temp1;
	int n;
	temp=head;
	if(temp=='\0')
	{
	 printf("\n there is no element in list");

	}
	else
	{
		while(temp->next!='\0')
		{
			if(temp->info%2!=0 || temp->info==1)
			{
			    if(temp->prev=='\0') //for first node
			    {
					head=temp->next;
					temp1=temp;
					temp1->next='\0';
					n=temp->info;
					temp=head;
					free(temp1);
					printf("\n 1one node deleted with value=%d",n);
			    }//if
				else if(temp->next=='\0')//for last node
				{
					temp1=tail;
					tail=tail->prev;
					n=temp->info;
					tail->next='\0';
					 temp1->prev='\0';
					free(temp1);
					printf("\n 2one node deleted with value=%d",n);
				}
				else//for normal condition
				{

					temp1=temp;
					temp=temp->prev;
					n=temp1->info;
					temp->next=temp1->next;
					temp1->next->prev=temp;
					temp1->next='\0';
					temp1->prev='\0';
					free(temp1);
					printf("\n 3one node deleted with value=%d",n);
				}//else
			}
		  temp=temp->next;
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
	dodd();
	printf("\n list after deletion::");
	disp();
	getch();

}